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
	swap(arr, more, R);//当遍历结束之后(指针相遇)，将枢轴x与大于x的第一位上的数(数组下标为more的数)进行交换
	
}

void doubleSideSort(vector<int>& vec1, int head, int tail)	//序列与左右指针传入
{
	//结束语
	if (tail == head)
		return;

	//基准确定
	int flag = vec1[head];
	int keep_tail = tail;
	int keep_head = head;
	int change_temp;

	//当左右指针还没重合
	while (head < tail)
	{
		//左指针先走
		while (head < tail && vec1[head] <= flag)
		{
			head++;
		}//当遇到比基准大的数，停下来

		//轮到右指针走
		while (head < tail && vec1[tail] >= flag)	//可以都等，反正最后都会归并
		{
			tail--;
		}//当遇到比基准小的数，停下来

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
		//然后继续循环
	}

	//head--;

	//接着将基准放进去，此时必定是左右相合，则左值若大于左值左边一位，和左值左边一位换，若小，则和左值换
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
