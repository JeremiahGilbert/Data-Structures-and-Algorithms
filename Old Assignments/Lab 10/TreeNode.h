#pragma once

#include <memory>

class TreeNode : public std::enable_shared_from_this<TreeNode> {
public:
	TreeNode(int value);
	~TreeNode();

	std::shared_ptr<TreeNode> getParent();

	int getValue();

	void setLeft(std::shared_ptr<TreeNode> tree);
	void setRight(std::shared_ptr<TreeNode> tree);

	static std::shared_ptr<TreeNode> treeSearch(std::shared_ptr<TreeNode> tree, int value);
	static std::shared_ptr<TreeNode> treeMin(std::shared_ptr<TreeNode> tree);
	static std::shared_ptr<TreeNode> treeMax(std::shared_ptr<TreeNode> tree);
	static std::shared_ptr<TreeNode> treeSuccessor(std::shared_ptr<TreeNode> tree);
	static std::shared_ptr<TreeNode> treePredecessor(std::shared_ptr<TreeNode> tree);
	static std::shared_ptr<TreeNode> treeInsert(std::shared_ptr<TreeNode> tree, int value);

	static void inorderTraverse(std::shared_ptr<TreeNode> tree);

private:
	void setParent(std::shared_ptr<TreeNode> tree);

	std::shared_ptr<TreeNode> left;
	std::shared_ptr<TreeNode> right;
	std::shared_ptr<TreeNode> parent;

	int value;
};
