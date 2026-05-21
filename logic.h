#pragma once
#include <string>

class logic {
public:
	logic(const std::string& fileName);
	void setWord(const std::string& newWord);
	std::string getWord() const;

	void readFile(const std::string& fileName);
	std::string getFirstScrambledWord(); //get word from word array, scramble it, return scrambled word
	

private:
	std::string word;
	std::string scramble;
	std::string words[100];
	std::string scrambledWords[100];

};