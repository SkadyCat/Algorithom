#pragma once
#include <iostream>
#include "node.h"
using namespace std;
Node* merge(Node* left, Node* right);
Node* breakList(Node * head,int layer) {
	if (head->next == nullptr) {
		return head;
	}
	Node* fast = head->next;
	Node* slow = head;
	while (fast != nullptr && fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
	}
	Node* nextHead = slow->next;
	slow->next = nullptr;
	Node* lmerge = breakList(head,layer+1);
	Node* rmerge = breakList(nextHead,layer+1);
	return merge(lmerge, rmerge);
}

Node* merge(Node* left, Node* right) {
		
	Node* parent = new Node(0);
	Node* reNode = parent;
	while (left != nullptr && right != nullptr) {
		Node* ltemp = left;
		Node* rtemp = right;
		if (ltemp->val >= rtemp->val) {
			parent->next = ltemp;
			parent = parent->next;
			left = left->next;
		}
		if (ltemp->val < rtemp->val) {
			parent->next = rtemp;
			parent = parent->next;
			right = right->next;
		}
	}
	while (left!= nullptr)
	{
		parent->next = left;
		left = left->next;
		parent = parent->next;
	}
	while (right!= nullptr)
	{
		parent->next = right;
		right = right->next;
		parent = parent->next;
	}
	return reNode->next;
}