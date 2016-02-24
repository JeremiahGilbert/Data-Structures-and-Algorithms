#pragma once

#include <memory>
#include <string>
#include <vector>

class TreeNode {
public:
	TreeNode(std::vector<int>& v, int index = 0);
	virtual ~TreeNode();

	std::string preorderTraverse();
	std::string inorderTraverse();
	std::string postorderTraverse();

private:
	int value;
	std::unique_ptr<TreeNode> left;
	std::unique_ptr<TreeNode> right;
};

