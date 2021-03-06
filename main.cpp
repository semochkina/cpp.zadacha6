#include <iostream>
#include "BinarySearchTree.h"


int main() {
	std::cout << "BinarySearchTree\n";

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

	BinarySearchTree tree2;
	tree2 = tree;

	std::cout << "\n";
	tree.del("seven");
	tree.del("one");
	tree.del("six");
	std::cout << "del(seven) " << "\n";
	std::cout << "del(one) " << "\n";
	std::cout << "del(six) " << tree << "\n";
	std::cout << "countAll() -  " << tree.countAll() << "\n";

//	std::cout << "\nBinarySearchTree2\n" << tree2 << "\n";

	std::cin.get();
	return 0;
}
