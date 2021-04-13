#pragma once
#include <ostream>
#include <string>
#include <vector>
using namespace std;
struct Node
{

	int val;
	Node* next;
	Node(int val) {
			
		next = nullptr;
		this->val = val;
	}
	Node* nextNode(Node* node) {
		
		next = node;
		return next;
	}

};
Node* sample() {
	
	Node* node = new Node(4);
	Node* temp = node->nextNode(new Node(1));
	temp = temp->nextNode(new Node(3));
	temp = temp->nextNode(new Node(7));
	temp = temp->nextNode(new Node(5));
	temp = temp->nextNode(new Node(9));
	temp = temp->nextNode(new Node(4));
	temp = temp->nextNode(new Node(6));
	temp = temp->nextNode(new Node(8));
	temp = temp->nextNode(new Node(1));
	return node;
}
void log(string info,Node* node, initializer_list<string> detail, initializer_list<int> args) {
	
	
	cout << info << ": ";
	Node* cur = node;
	
	while (cur != nullptr)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}

	vector<int> v1;
	for (auto k : args)
	{
		v1.push_back(k);
	}

	vector<string> v2;
	for (auto k : detail)
	{
		v2.push_back(k);
	}
	for (int i = 0; i < args.size(); i++) {

		cout << v2[i] << "=" << v1[i] << " ";
	}

	cout << endl;

}
