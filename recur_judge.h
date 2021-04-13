#pragma once

#include "binary_node.h"



bool help(TreeNode* left,TreeNode* right,int layer) {
	//末端叶子节点情况

	//cout << "layer = " << layer << endl;
	if (left == nullptr && right == nullptr)
	{
		return true;
	}
	
	if (left != nullptr && right != nullptr)
	{
		if (left->val != right->val)
		{
			return false;
		}
	}
	if (left == nullptr && right != nullptr || left != nullptr && right == nullptr)
	{
		return false;
	}

	bool f1 = help(left->left, right->right,layer+1);
	bool f2 = help(left->right, right->left,layer+1);
	return (left->val== right->val)&&f1&&f2;
}

bool test(TreeNode* head) {

	bool flag = help(head->left, head->right, 0);
	return flag;

}