#include "TreeNode.h"


TreeNode::TreeNode(std::vector<int>& v, int i) {
	value = v.at(i);
	int size = v.size();
	if (i * 2 + 1 < size) {
		left = std::make_unique<TreeNode>(v, i * 2 + 1);
	}
	if (i * 2 + 2 < size) {
		right = std::make_unique<TreeNode>(v, i * 2 + 2);
	}
}

TreeNode::~TreeNode() {}

std::string TreeNode::preorderTraverse() {
	std::string output;
	output.append(std::to_string(this->value) + " ");
	if (this->left) output.append(this->left->preorderTraverse());
	if (this->right) output.append(this->right->preorderTraverse());
	return (output);
}

std::string TreeNode::inorderTraverse() {
	std::string output;
	if (this->left) output.append(this->left->preorderTraverse());
	output.append(std::to_string(this->value) + " ");
	if (this->right) output.append(this->right->preorderTraverse());
	return (output);
}

std::string TreeNode::postorderTraverse() {
	std::string output;
	if (this->left) output.append(this->left->preorderTraverse());
	if (this->right) output.append(this->right->preorderTraverse());
	output.append(std::to_string(this->value) + " ");
	return (output);
}