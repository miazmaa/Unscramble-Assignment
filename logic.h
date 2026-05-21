#pragma once
#include <string>
class logic {
public:

	logic();
	void introduction();
	bool createLists(); //opens file, reads words, return true if it works and false otherwise
	bool playGame(); //return true if victory and false if not
	//get word from word array, scramble it, return scrambled word
	std::string scramble(std::string word); //take in word, scramble, return scrambled word
	void end(); //print final results, ie player message 
	
private:
	std::string word;
	std::string words[100];
	std::string currentWord;
	std::string scrambleWord(const std::string& word);
	std::string shortWords[50]; //4-5 letter words
	std::string mediumWords[50]; //6-7 letter words
	std::string longWords[50]; //8+ letter words
	int numCorrect,
		smallWordLength,
		mediumWordLength,
		LargeWordLength;
};