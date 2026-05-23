#include "logic.h"
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
using namespace std;
logic::logic() {
	numCorrect = 0;
	smallWordLength = 0;
	mediumWordLength = 0;
	largeWordLength = 0;
}

void logic::introduction() {
	cout << "This is a word unscramble game!";
	cout << "You will have 5 words to unscramble in 60 seconds with varying lengths.";
	cout << "The amount of words you properly unscramble will decide your intellect! Aim for the highest score!";
	cout << "Good luck! I believe in you!";
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
	for (int i = 0; i < 2; i++) {
		int index = rand() % smallWordLength;
		selectedWords[i] = smallWords[index];
	}
	for (int i = 2; i < 4; i++) {
		int index = rand() % mediumWordLength;
		selectedWords[i] = mediumWords[index];
	}
	int index = rand() % largeWordLength;
	selectedWords[4] = largeWords[index]; //picks 5 random words from the arrays to add into the current array for this round
}

string logic::scramble(string word) {
	random_device random;
	mt19937 scrambler(random());
	shuffle(word.begin(), word.end(), scrambler);
	return word;
}

void logic::end() {
	cout << "Game Over! You successfully unscrambled " << numCorrect << " out of 5 words!";
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