#pragma once
#include "BotQA.h"
#include "Trie.h"

class BotBrain
{
public:
	static shared_ptr<BotBrain> botInstance;

public:
	BotBrain(KnowledgeEntry data[]);
	virtual ~BotBrain();
	
	const string& ask(const string& question);

	// Helpers
private:
	void enterData(KnowledgeEntry data[]);
	void findAllMatches(const string& userQuestion, vector<int>& candidateAnswers);
	void getBestMatch(pair<int, int>& occurance, vector<int>& candidateAnswers);
	const string& getDefaultAnswer();
private:
	Trie wordMap;
};

static BotBrain& getBotInstance(string& name) {
	BotBrain::botInstance = make_shared<BotBrain>(knowledgeBase);
	
	return *BotBrain::botInstance;
}



