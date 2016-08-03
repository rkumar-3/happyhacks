#include "Trie.h"
#include <memory>

// constructor(s)/destrcutor
Trie::Trie()
{
	tree = make_node(NULL);
}


Trie::~Trie()
{
}


//
// public interface
//


// adds a word into the 'trieTree',
void Trie::insert(const string& s, const int index) 
{
	shared_ptr<Node> treeNode = tree;

	// iterates and adds each character in the string to the tree
	for (int i = 0; i < s.size(); i++) {
		shared_ptr<Node> next = putChar(s.at(i), treeNode);
		treeNode = next;
	}

	// puts an index to original source for the word into the last alphabet
	endMarker(treeNode, index);
}

// Searches for the occurence of a word in the trieTree
wordInfo Trie::search(const string& s)
{
	shared_ptr<Node> treeNode = tree;

	int index = 0;
	for (;index < s.size(); index++) {
		char alphabet = __ascii_tolower(s[index]) - 'a';

		if (treeNode->children[alphabet] != NULL) {
			treeNode = treeNode->children[alphabet];
		}
		else {
			break;
		}
	}

	// if we have a valid word, return additional info saved at it's last character
	wordInfo& info = emptyOccurance;
	if (index == s.size() && !treeNode->data.empty()) {
		info = treeNode->data;
	}

	return info;
}

void Trie::remove(const string& s) 
{
	/* To Do*/
}

void Trie::printAll() 
{
	/* To Do*/
}

/**
  *-------------HELPERS---------------------
  */


  /**
    * Inserts the given character by creating a child node.
    */
shared_ptr<Node> 
Trie::putChar(char c, shared_ptr<Node> treeNode) {
	char ialphabet = __ascii_tolower(c) - 'a';

	if (NULL == treeNode->children[ialphabet].get()) {
		treeNode->children[ialphabet] = make_node(treeNode); // inserts a node to represent the alphabet			
	}

	return treeNode->children[ialphabet];
}

/**
  * Index points to the source sentence(s) that this word is part of.
  * 
  * e.g. "How many medals?" is the source sentence. 
  * The three words that form this sentence are then saved into our Trie knowledgebase.
  *
  * When the word, "How" is put into the trie, an index value to retrieve the source sentence 
  * is saved into the node representing last character "w"
  * 
  * This comes in handy when we find a match for the word and want to know what 
  * are all the source sentences this word is part of!
  */
void Trie::endMarker(shared_ptr<Node> treeNode, int index) {
	treeNode->data.push_back(index); 
}
