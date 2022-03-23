#include <iostream>
#include "Trie-tree.h"

int main() {
	int numberC, queryC, x;
	std::cout << "Enter count of numbers (n>0):";
	std::cin >> numberC;
	std::cout << "Enter count of query (q>0): ";
	std::cin >> queryC;

	TrieNode* root = nullptr;
	std::string numbers;
	std::cout << "\nEnter your number (a1,a2,a3,...,an):";
	for (size_t i = 0; i < numberC; i++)
	{
		std::cin >> numbers;
		insert(root, numbers);
	}

	//std::cout << "\nYou entered: ";
	//printTree(root);


	std::cout << "\nEnter your query:";
	for (size_t i = 0; i < queryC; i++)
	{
		std::cout << "\nEnter x:";
		std::cin >> x;
		std::cout << "\nFor " << x << " max XOR number in string is :" << maxXOR(root, x)<<"\n";
	}

	std::cin.ignore().get();
	return 0;
}