#include <iostream>
#include <memory>
#include <vector>

#include "TreeNode.h"



int main() {
	std::vector<int> input = {17, 6, 19, 3, 16, 18, 20, 2, 4, 14, 13, 15};
	std::shared_ptr<TreeNode> tree;
	for (auto x : input) {
		tree = TreeNode::treeInsert(tree, x);
	}

	TreeNode::inorderTraverse(tree);

	for (int i = 1; i <= 20; ++i) {
		std::shared_ptr<TreeNode> found = TreeNode::treeSearch(tree, i);
		if (found) {
			if (found->getParent())
				std::cout << i << " found: parent is " << found->getParent()->getValue() << std::endl;
			else std::cout << i << " found: parent is null" << std::endl;
		} else {
			std::cout << i << " not found." << std::endl;
		}
	}

	for (int i = 1; i <= 20; ++i) {
		std::shared_ptr<TreeNode> found = TreeNode::treeSearch(tree, i);
		if (found) {
			std::shared_ptr<TreeNode> predecessor = TreeNode::treePredecessor(found);
			if (predecessor) {
				std::cout << i << " found: predeccessor is " << predecessor->getValue() << std::endl;
			}
		}
	}

	return 0;
}