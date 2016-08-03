// botBrain.cpp.
//

#include "stdafx.h"
#include "BotBrain.h"
#include <sstream>
#include <map>

shared_ptr<BotBrain> BotBrain::botInstance;

// constructor(s)/destrcutor

BotBrain::BotBrain(KnowledgeEntry data[])
{
	enterData(data);
}


BotBrain::~BotBrain()
{
}

//
// public interface
//


// calculates a simple weight based on the number of occurance 
// of the words in our pre-built questions and helps select the 
// pre-built query with maximum match

const string& BotBrain::ask(const string& question) 
{
	vector<int> candidateAnswers(MAX_KNOWLEDGE_ENTRIES, 0);

	// returns all matching pre-built quries with close enough match
	findAllMatches(question, candidateAnswers);
	
	// returns the pre-built query that matches closely to the question
	pair<int, int> occurance(-1, -1);
	getBestMatch(occurance, candidateAnswers);

	// returns the corresponding answer.
	const string& defaultAnswer = getDefaultAnswer();
	if (occurance.second > 0) {
		return knowledgeBase[occurance.first].second;
	}

	return defaultAnswer;
}

/**
*-------------HELPERS---------------------
*/

// returns all matching pre-built inquires
void BotBrain::findAllMatches(const string& userQuestion, vector<int>& candidateAnswers) {
	stringstream ss(userQuestion);

	string token;
	while (ss >> token) {
		wordInfo info = wordMap.search(token);

		for (int qIndex : info) {
			candidateAnswers.at(qIndex)++;
		}
	}
}

void BotBrain::getBestMatch(pair<int, int>& occurance, vector<int>& candidateAnswers) {
	int index = 0;
	for (int val : candidateAnswers) {
		if (val > occurance.second) {
			occurance.first = index++;
			occurance.second = val;
		}
	}
}

const string& BotBrain::getDefaultAnswer() {
	return knowledgeBase[MAX_KNOWLEDGE_ENTRIES - 1].second;
}

void BotBrain::enterData(KnowledgeEntry data[])
{
	int index = 0;

	while(index < MAX_KNOWLEDGE_ENTRIES) {
		const string& sentence = data[index].first;

		stringstream ss(sentence);
		string token;
		while (ss >> token) {
			wordMap.insert(token, index);
		}
		index++;
	}
}

int main()
{
	// get the named bot!
	string name = "SportsNews";
	BotBrain bot = getBotInstance(name);


	// ask the bot a question!
	string word = "Total medals for India";
	const string& answer = bot.ask(word);

	return 0;
}

