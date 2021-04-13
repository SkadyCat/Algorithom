#pragma once


struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int val) {
		left = nullptr;
		right = nullptr;
		this->val = val;
	}
	TreeNode* addLeft(TreeNode* left) {

		this->left = left;
		return left;
	}
	TreeNode* addRight(TreeNode* right) {
		
		this->right = right;
		return right;
	}
	
};

TreeNode* example1() {

	TreeNode* head = new TreeNode(1);
	TreeNode* left = head->addLeft(new TreeNode(1));
	TreeNode* right = head->addRight(new TreeNode(1));
	left->addLeft(new TreeNode(2));
	left->addRight(new TreeNode(3));
	right->addLeft(new TreeNode(3));
	right->addRight(new TreeNode(2));

	return head;
}
