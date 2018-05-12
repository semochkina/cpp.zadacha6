#include <iostream>
#include "BinarySearchTree.h"


int main() {
	std::cout << "\nBinarySearchTree\n";

	BinarySearchTree tree;
	tree.add("5");
	tree.add("1");
	tree.add("6");
	tree.add("3");
	tree.add("4");
	tree.add("5");
	tree.add("2");
	tree.add("6");
	tree.add("7");
	tree.add("8");
	tree.add("9");

	std::cout << "\n" << tree << "\n";

	std::cout << "find(11) - " << tree.find("11") << "\n";
	std::cout << "find(6) - " << tree.find("6") << "\n";

	std::cout << "countAll() -  " << tree.countAll() << "\n";

	std::cout << "\n";
	tree.del("7");
	std::cout << "del(7) " << tree << "\n";

	std::cout << "countAll() -  " << tree.countAll() << "\n";

	std::cin.get();
	return 0;
}
