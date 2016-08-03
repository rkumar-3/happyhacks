#pragma once

// headers
#include "Node.h"
#include "TrieInterface.h"

using namespace std;

// constants
#define IS_UPPERCASE(c) ((c > 'A'))

/**
  * class implements a Trie data structure for fast search of a word in O(L) time. 
  * where L represents the word length.
  */
class Trie : public TrieInterface
{
public:
	Trie();
	virtual ~Trie();

	virtual void insert(const string& s, const int index);
	virtual wordInfo search(const string& s);
	virtual void remove(const string& s);
	virtual void printAll();

	// Helpers
private:
	shared_ptr<Node> putChar(char c, shared_ptr<Node> treeNode);
	void endMarker(shared_ptr<Node> treeNode, int index);
private:
	shared_ptr<Node> tree;
	vector<int> emptyOccurance;
};

