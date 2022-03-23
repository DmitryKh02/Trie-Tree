#pragma once
#include <string>

const int ALPHABET_SIZE = 10;

struct TrieNode {
	struct TrieNode* children[ALPHABET_SIZE];
	bool isEndOfWord;
};


struct TrieNode* createNode(){
	struct TrieNode* pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = nullptr;

	return pNode;
}


void insert(struct TrieNode*& root, std::string key) {
	struct TrieNode* pNode = root;

	if (pNode == nullptr) {
		pNode = createNode();
		root = pNode;
	}

	for (size_t i = 0; i < key.length(); i++)
	{
		int index = key[i] - '0';

		if (!pNode->children[index])
			pNode->children[index] = createNode();
		pNode = pNode->children[index];
	}
	
	pNode->isEndOfWord = true;
}


bool search(struct TrieNode* root, std::string key) {
	bool result = false;
	struct TrieNode* pNode = root;
	if (pNode != nullptr) {
		for (int i = 0; i < key.length(); i++) {
			int index = key[i] - '0';

			if (!pNode->children[index]) result = false;

			pNode = pNode->children[index];
		}
		result = pNode->isEndOfWord;
	}
	return result;
}

TrieNode* deleteElem(struct TrieNode* root, std::string key, int place = 0) {

	struct TrieNode* pNode = root;
	
	if (pNode != nullptr) {

		if (place < key.length()) {
			int index = key[place] - '0';
			if (pNode->children[index]) pNode = deleteElem(pNode->children[index], key, place + 1);
		}
		else {

			bool isEnd = true;
			for (size_t i = 0; i < ALPHABET_SIZE; i++)
			{
				if (pNode->children[i] != nullptr) isEnd = true;
			}

			if (isEnd) {
				delete pNode->children;
				pNode = nullptr;
			}
			else pNode->isEndOfWord = false;
		}
	}
	
	return pNode;
}

int maxXOR(TrieNode* root, int number, int result = 0){
	int masXOR[10]{ 0,0,0,0,0,0,0,0,0,0 };
	int max = 0;
	int Xor= 0;
	for (size_t i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->children[i] != nullptr)
		{
			result = result * 10 + i;
			masXOR[i] = maxXOR(root->children[i], number, result);
			result = result / 10;
		}
		else if (root->isEndOfWord) {
			Xor = result ^ number;
			max = result;
		}
		
	}
	for (size_t i = 0; i < ALPHABET_SIZE; i++)
	{
		if ((masXOR[i] ^ number) > Xor && masXOR[i] != 0)
		{
			max = masXOR[i];
			Xor = masXOR[i] ^ number;
		}
	}
	return max;
}

void printTree(struct TrieNode* root)
{
	TrieNode* pNode = root;
	for (size_t i = 0; i < ALPHABET_SIZE; i++)
	{
		if (pNode->children[i] != nullptr) {
			std::cout << i;
			printTree(pNode->children[i]);
		}
	}
	std::cout << "\n";
}