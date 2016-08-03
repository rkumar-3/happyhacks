#pragma once
#include <utility>
#include <string>

using namespace std;

typedef const pair<string, string> KnowledgeEntry;
const int MAX_KNOWLEDGE_ENTRIES = 5;
static KnowledgeEntry knowledgeBase[MAX_KNOWLEDGE_ENTRIES] = {
	{ "How many gold medals does India have from Olympics", "10" },
	{ "Total medals for India in Olympics?", "10" },
	{ "How many medals", "10" },
	{ "Do they have a chance for athletics gold in Rio?", "Unlikely says my Poncho brain" },
	{"SENTINEL", "Sorry. I don't have an answer for your question. Insufficient data"}
};

