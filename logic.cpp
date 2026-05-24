#include "logic.h"
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
using namespace std;
extern bool finished;
extern bool timeOut;
logic::logic() {
	numCorrect = 0;
	smallWordLength = 0;
	mediumWordLength = 0;
	largeWordLength = 0;
}

void logic::introduction() {
	cout << "This is a word unscramble game! \n";
	cout << "You will have 5 words to unscramble in 60 seconds with varying lengths. \n";
	cout << "The amount of words you properly unscramble will decide your intellect! Aim for the highest score! \n";
	cout << "Good luck! I believe in you! \n";
}

bool logic::createLists() {
	ifstream wordBank("dictionary.txt");
	if (!wordBank) {
		cout << "ERROR: reading text file failed.";
		return false;
	}
	string word; //equals the line currently being read in dictionary.txt, will be a single word
	while (wordBank >> word) { //this loop reads the word into one of 3 arrays if it fits the word length criteria
		int wordLength = word.length();
		if (wordLength == 4 || wordLength == 5) {
			smallWords[smallWordLength] = word;
			smallWordLength++;
		}
		else if (wordLength == 6 || wordLength == 7) {
			mediumWords[mediumWordLength] = word;
			mediumWordLength++;
		}
		else if (wordLength >= 8) {
			largeWords[largeWordLength] = word;
			largeWordLength++;
		}
	}
	return true;
}
bool logic::playGame() {
	//picks 5 random words from the arrays to add into the current array for this round
	for (int i = 0; i < 2; i++) {
		int index = rand() % smallWordLength;
		selectedWords[i] = smallWords[index];
	}
	for (int i = 2; i < 4; i++) {
		int index = rand() % mediumWordLength;
		selectedWords[i] = mediumWords[index];
	}
	int index = rand() % largeWordLength;
	selectedWords[4] = largeWords[index]; 
	//proper gameplay loop:
	for (int i = 0; i < 5; i++) {
		string scrambledWord = scramble(selectedWords[i]); //scrambles the word chosen per round 
		cout << "Unscramble: " << scrambledWord << "\n";
		string userGuess;
		while (!timeOut && !finished) {
			cin >> userGuess;
			if (timeOut) {
				cout << "You ran out of time! \n";
				return false; //returns player loss if time ever runs out
			}
			if (userGuess == selectedWords[i]) {
				cout << "Great job! \n";
				numCorrect++;
				break;
			}
			else {
				cout << "Wrong! Try again. \n"; //user stays on the same word until they guess correctly or time runs out
			}
		}
	}
	finished = true;
	return true;
}

string logic::scramble(string word) {
	int wordLength = word.length();
	for (int i = 0; i < wordLength; i++) {
		int charOneSwap = rand() % wordLength;
		int charTwoSwap = rand() % wordLength;
		char copy = word[charOneSwap];
		word[charOneSwap] = word[charTwoSwap];
		word[charTwoSwap] = copy;

	}
	return word;
}

void logic::end() {
	cout << "Game Over! You successfully unscrambled " << numCorrect << " out of 5 words! \n";
	switch (numCorrect) {
	case 2:
		cout << "Keep practicing! I know you can do better next time.";
		break;
	case 3:
		cout << "Not bad! But maybe you can shoot even higher...?";
		break;
	case 4: 
		cout << "Super impressive! You're almost at the peak!";
		break;
	case 5:
		cout << "You're a genius! No one's smarter than you!";
		break;
	}
}