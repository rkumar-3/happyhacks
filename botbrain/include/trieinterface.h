#pragma once
#include <string>
#include <vector>
using namespace std;

typedef vector<int>& wordInfo;

// Interface defines apis to impl. for a Trie data structure
class TrieInterface
{
public:
	virtual void insert(const string& s, const int index) = 0;
	virtual wordInfo search(const string& s) = 0;
	virtual void remove(const string& s) = 0;
	virtual void printAll() = 0;
};
