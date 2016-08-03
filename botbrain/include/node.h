#pragma once
#include <vector>
#include <memory>

using namespace std;

static const int SIZEOF_ASCII_CSET = 26;

struct Node {
	shared_ptr<Node>		children[SIZEOF_ASCII_CSET];
	shared_ptr<Node>		parent;
	vector<int>				data; // index to additional info. on the word.

	Node() : parent(NULL) {
		for (int i = 0; i < SIZEOF_ASCII_CSET; i++) {
			children[i] = NULL;
		}
	};
};

static shared_ptr<Node> make_node(shared_ptr<Node> parent) {
	shared_ptr<Node> node = make_shared<Node>(); // create a new node
	node->parent = parent;	// set parent

	return node;
};
