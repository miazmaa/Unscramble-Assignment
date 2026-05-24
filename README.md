The following is a Word Scrambler game. It reads a text file and stores words into 3 different arrays based on the word size:
1. 4-5 letter words
2. 6-7 letter words
3. 8+ letter words
The program pulls 5 words across the 3 arrays for a run of the game: 2 from the small word array, 2 from the medium word array, 1 from the long word array.
It then scrambles the 5 words chosen and displays them to the screen. The user inputs guesses of the initial word before it was scrambled.
The user moves through rounds if they properly guess the word.
Once 60 seconds are up, or the user finishes guessing all 5 words, a game over message is displayed to the screen.
If the user got 2+ words correct, a victory message is displayed measuring their intellect.
Allegro is used for the project. A main thread keeps track of the game and a Timer thread keeps track of the timer.
