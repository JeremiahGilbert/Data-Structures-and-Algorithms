#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "TreeNode.h"

std::string preorderTraverse(std::vector<int>& v, int index = 0);
std::string inorderTraverse(std::vector<int>& v, int index = 0);
std::string postorderTraverse(std::vector<int>& v, int index = 0);

int main() {
	std::vector<int> input(10);
	std::for_each(input.begin(), input.end(), [](int& i) {static int count = 0; i = count; ++count; });

	std::cout << "Preorder:\t" << preorderTraverse(input) << std::endl;
	std::cout << "Inorder:\t" << inorderTraverse(input) << std::endl;
	std::cout << "Postorder:\t" << postorderTraverse(input) << std::endl;

	std::cout << std::endl;

	std::unique_ptr<TreeNode> tree = std::make_unique<TreeNode>(input);
	std::cout << "Tree preorder\t" << tree->preorderTraverse() << std::endl;
	std::cout << "Tree inorder\t" << tree->inorderTraverse() << std::endl;
	std::cout << "Tree postorder\t" << tree->postorderTraverse() << std::endl;

	return (0);
}

std::string preorderTraverse(std::vector<int>& v, int index) {
	std::string output;
	if (index < v.size()) {
		output.append(std::to_string(v.at(index)) + " ");
		output.append(preorderTraverse(v, index * 2 + 1));
		output.append(preorderTraverse(v, index * 2 + 2));
	}
	return (output);
}

std::string inorderTraverse(std::vector<int>& v, int index) {
	std::string output;
	if (index < v.size()) {
		output.append(preorderTraverse(v, index * 2 + 1));
		output.append(std::to_string(v.at(index)) + " ");
		output.append(preorderTraverse(v, index * 2 + 2));
	}
	return (output);
}

std::string postorderTraverse(std::vector<int>& v, int index) {
	std::string output;
	if (index < v.size()) {
		output.append(preorderTraverse(v, index * 2 + 1));
		output.append(preorderTraverse(v, index * 2 + 2));
		output.append(std::to_string(v.at(index)) + " ");
	}
	return (output);
}