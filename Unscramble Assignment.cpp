#include <cstdlib>
#include <iostream>
#include <allegro5/allegro.h>
#include "logic.h"
#include <allegro5/allegro_native_dialog.h>
using namespace std;

bool finished = false;
bool timeOut = false;

void* timer(ALLEGRO_THREAD* ptr, void* arg);

int main(int argc, char* argv[])
{
	srand(time(NULL));

	if (!al_init()) {
		al_show_native_message_box(NULL, NULL, NULL, "failed to initialize allegro!", NULL, NULL);
		return -1;
	}
	logic game;
	game.introduction();
	game.createLists();
	
	if (!game.createLists()) {
		return -1; //program ends if it cannot get information from dictionary.txt
	}

	ALLEGRO_THREAD* timerThread = al_create_thread(timer, NULL);

	al_start_thread(timerThread);

	game.playGame();

	finished = true;

	al_join_thread(timerThread, NULL);

	al_destroy_thread(timerThread);

	game.end();

}

// A pointer to a function that prompts the user for input
void* input(ALLEGRO_THREAD* ptr, void* arg)
{
	finished = false;
	cout << "Asking for user Input?";
	cin >> finished;
	finished = true;
	return NULL;
}
// A pointer to a function that starts the timer and checks the change in
// finished, which is in the input thread.
void* timer(ALLEGRO_THREAD* ptr, void* arg)
{
	time_t startTime = time(NULL);
	while (!finished) {
		time_t currentTime = time(NULL);
		if (currentTime - startTime >= 60) {
			timeOut = true; //thread ends if timer passes 60
			break;
		}
	}
	return NULL;
}

