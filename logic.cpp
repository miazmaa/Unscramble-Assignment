#include "logic.h"
logic::logic(const std::string& fileName)
{
	//open file
	//loop to read line by line
	//store the words/line read in word[i]
	//take in word, scramble it, store in scrambledWords[i]
	word = "";
	scramble = "";
	for (int i = 0;i < 100;i++)
		words[i] = "";

}
void logic::setWord(const std::string& newWord) {
	word = newWord;
}
std::string logic::getWord() const {
	return word;
}
