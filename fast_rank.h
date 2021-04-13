#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "debug.h"

static void swap(vector<int> arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
static void patition(vector<int> arr, int L, int R) {
	int less = L - 1;
	int more = R;
	int cur = L;
	while (cur < more) {

		if (arr[cur] < arr[R]) {
			swap(arr, ++less, cur++);
		}
		else if (arr[cur] > arr[R]) {
			swap(arr, --more, cur);
		}
		else {
			cur++;
		}
	}
	swap(arr, more, R);//����������֮��(ָ������)��������x�����x�ĵ�һλ�ϵ���(�����±�Ϊmore����)���н���
	
}

void doubleSideSort(vector<int>& vec1, int head, int tail)	//����������ָ�봫��
{
	//������
	if (tail == head)
		return;

	//��׼ȷ��
	int flag = vec1[head];
	int keep_tail = tail;
	int keep_head = head;
	int change_temp;

	//������ָ�뻹û�غ�
	while (head < tail)
	{
		//��ָ������
		while (head < tail && vec1[head] <= flag)
		{
			head++;
		}//�������Ȼ�׼�������ͣ����

		//�ֵ���ָ����
		while (head < tail && vec1[tail] >= flag)	//���Զ��ȣ�������󶼻�鲢
		{
			tail--;
		}//�������Ȼ�׼С������ͣ����

		//if (head == tail) {
		//	break;
		//}
		log("origin", vec1, { "head","tail","headValue","tailValue" }, { head, tail, vec1[head], vec1[tail] });
		if (head < tail)
		{
			change_temp = vec1[head];
			vec1[head] = vec1[tail];
			vec1[tail] = change_temp;
		}


		log("change", vec1, { "head","tail","headValue","tailValue" }, { head, tail, vec1[head], vec1[tail] });
		//Ȼ�����ѭ��
	}

	//head--;

	//���Ž���׼�Ž�ȥ����ʱ�ض���������ϣ�����ֵ��������ֵ���һλ������ֵ���һλ������С�������ֵ��
	if (vec1[head] > vec1[head - 1])
	{
		vec1[keep_head] = vec1[head - 1];
		vec1[head - 1] = flag;
	}
	else
	{
		vec1[keep_head] = vec1[head];
		vec1[head] = flag;
	}
	log("insert", vec1, {}, {});
	doubleSideSort(vec1, 0, head - 1);
	doubleSideSort(vec1, tail, keep_tail);
}


void frank2(vector<int>& data,int begin,int end) {

	int pivot = data[begin];
	int fast = end;
	int slow = end;

	while (fast > begin)
	{
		
		
		if (data[fast] > pivot) {
			//log("origin", data, { fast, data[fast],slow,data[slow] });
			int temp = data[fast];
			data[fast] = data[slow];
			data[slow] = temp;
			slow--;
			
		}
		//log("change", data, { fast, data[fast],slow,data[slow] });
		fast--;
	}
}

void frank(vector<int>& data, int begin, int end, int layer, string temp) {
	if (begin >= end) {
		return;
	}
	int sd = data[begin];
	vector<int> svec;
	vector<int> lvec;
	vector<int> evec;
	for (int i = begin; i < end; i++) {
		if (data[i] < sd) {
			svec.push_back(data[i]);
		}
		if (data[i] > sd) {
			lvec.push_back(data[i]);
		}
		if (data[i] == sd) {
			evec.push_back(data[i]);
		}
	}
	int tb = begin;
	for (int i = 0; i < svec.size(); i++) {
		data[i + tb] = svec[i];
	}
	int mid = begin + svec.size();
	int mid2 = begin + svec.size() + evec.size() - 1;
	tb += svec.size();
	for (int i = 0; i < evec.size(); i++) {
		data[i + tb] = evec[i];
	}
	tb += evec.size();
	for (int i = 0; i < lvec.size(); i++) {
		data[i + tb] = lvec[i];
	}
	frank(data, begin, mid,layer+1,"head");
	frank(data, mid2+1, end,layer+1,"tail");
}
