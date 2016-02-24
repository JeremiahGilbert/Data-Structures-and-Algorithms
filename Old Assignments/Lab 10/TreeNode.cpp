#include "TreeNode.h"

#include <iostream>

TreeNode::TreeNode(int value) {
	this->value = value;
}

TreeNode::~TreeNode() {}

std::shared_ptr<TreeNode> TreeNode::getParent() {
	return this->parent;
}

int TreeNode::getValue() {
	return this->value;
}

void TreeNode::setLeft(std::shared_ptr<TreeNode> tree) {
	this->left = tree;
	tree->setParent(shared_from_this());
}

void TreeNode::setRight(std::shared_ptr<TreeNode> tree) {
	this->right = tree;
	tree->setParent(shared_from_this());
}

std::shared_ptr<TreeNode> TreeNode::treeSearch(std::shared_ptr<TreeNode> tree, int value) {
	if (!tree || value == tree->value) {
		return tree;
	} else if (value < tree->value) {
		return treeSearch(tree->left, value);
	} else {
		return treeSearch(tree->right, value);
	}
}

std::shared_ptr<TreeNode> TreeNode::treeMin(std::shared_ptr<TreeNode> tree) {
	while (tree->left) {
		tree = tree->left;
	}
	return tree;
}

std::shared_ptr<TreeNode> TreeNode::treeMax(std::shared_ptr<TreeNode> tree) {
	while (tree->right) {
		tree = tree->right;
	}
	return tree;
}

std::shared_ptr<TreeNode> TreeNode::treeSuccessor(std::shared_ptr<TreeNode> tree) {
	if (tree->right) {
		return treeMin(tree->right);
	} else {
		std::shared_ptr<TreeNode> p = tree->parent;
		while (p && tree == p->right) {
			tree = p;
			p = tree->parent;
		}
		return p;
	}
}

std::shared_ptr<TreeNode> TreeNode::treePredecessor(std::shared_ptr<TreeNode> tree) {
	if (tree->left) {
		return treeMax(tree->left);
	} else {
		std::shared_ptr<TreeNode> p = tree->parent;
		while (p && tree == p->left) {
			tree = p;
			p = tree->parent;
		}
		return p;
	}
}

std::shared_ptr<TreeNode> TreeNode::treeInsert(std::shared_ptr<TreeNode> tree, int value) {
	if (!tree) {
		std::shared_ptr<TreeNode> n = std::make_shared<TreeNode>(value);
		return n;
	} else if (value < tree->value) {
		tree->setLeft(treeInsert(tree->left, value));
	} else if (value > tree->value) {
		tree->setRight(treeInsert(tree->right, value));
	} else {
		throw std::exception("Value exists.");
	}
	return tree;
}

void TreeNode::inorderTraverse(std::shared_ptr<TreeNode> tree) {
	if (tree) {
		inorderTraverse(tree->left);
		std::cout << tree->value << std::endl;
		inorderTraverse(tree->right);
	}
}

void TreeNode::setParent(std::shared_ptr<TreeNode> tree) {
	this->parent = tree;
}
