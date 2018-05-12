#include <iostream>
#include "BinarySearchTree.h"


int main() {
	std::cout << "\nBinarySearchTree\n";

	BinarySearchTree tree;
	tree.add("five");
	tree.add("one");
	tree.add("six");
	tree.add("three");
	tree.add("four");
	tree.add("five");
	tree.add("two");
	tree.add("six");
	tree.add("seven");
	tree.add("eight");
	tree.add("nine");

	std::cout << "\n" << tree << "\n";

	std::cout << "find(eleven) - " << tree.find("eleven") << "\n";
	std::cout << "find(six) - " << tree.find("six") << "\n";

	std::cout << "countAll() -  " << tree.countAll() << "\n";

	std::cout << "\n";
	tree.del("seven");
	tree.del("one");
	tree.del("six");
	std::cout << "del(seven) " << tree << "\n";

	std::cout << "countAll() -  " << tree.countAll() << "\n";

	std::cin.get();
	return 0;
}
