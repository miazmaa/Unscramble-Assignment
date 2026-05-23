#include "logic.h"
#include <iostream>
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
//do this part later im lazy
bool logic::createLists() {

}
//this too
bool logic::playGame() {

}
//and this
string logic::scramble(string word) {

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