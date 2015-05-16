// Hangman
// The classic game of hangman

// TJW: Developed from the example in Chapter 4 of Beginning C++ Through
// Game Programming, Edition Three, by Michael Dawson

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main() 
{
	// setup
	const int MAX_WRONG = 8;	// maximum number of incorrect guesses allowed

	vector<string> words;		// collection of possible words to guess
	/*words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	words.push_back("ILOVEYOU");
	words.push_back("ALWAYS");*/
	words.push_back("RYE");
	// when adding new words, ensure they are in UPPERCASE

	string answer; // keeps track of if the player wants to play again. 

	cout << "Welcome to Hangman. Good luck!\n";

	// Play again loop. 
	do
	{
		answer = "";	// reset so the user is asked again at the bottom

		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(words.begin(), words.end());

		const string THE_WORD = words[0];		// word to guess
		int wrong = 0;							// number of incorrect guesses
		string soFar(THE_WORD.size(), '-');		// word guessed so far
		string used = "";						// letters already guessed
			
		// main game loop
		while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
		{
			cout << "\n\nYou have " << (MAX_WRONG - wrong);
			cout << " incorrect guesses left.\n";
			cout << "\nYou've used the following letters:\n" << used << endl;
			cout << "\nSo far, the word is:\n" << soFar << endl;

			char guess;
			cout << "\n\nEnter your guess: ";
			cin >> guess;
			guess = toupper(guess);	// make uppercase since secret word is in uppercase
			while (used.find(guess) != string::npos)
			{
				cout << "\nYou've already guessed " << guess << endl;
				cout << "Enter your guess: ";
				cin >> guess;
				guess = toupper(guess);
			}

			used += guess;

			if (THE_WORD.find(guess) != string::npos)
			{
				cout << "That's right! " << guess << " is in the word.\n";
				for (int i = 0; i < THE_WORD.length(); ++i)
				{
					if (THE_WORD[i] == guess)
					{
						soFar[i] = guess;
					}
				}
			}
			else
			{
				cout << "Sorry, " << guess << " isn't in the word.\n";
				++wrong;
			}
		}

		// shut down
		if (wrong == MAX_WRONG)
		{
			cout << "\nYou've been hanged! :'(";
		}
		else
		{
			cout << "\nYou guessed it!";
		}

		cout << "\nThe word was " << THE_WORD << endl;

		while (true)
		{
			if (answer == "") {
				// Ask if they want to play again
				cout << "\n\nDo you want to play again? Enter y for yes or n for no.\n";
				cin >> answer;
			}
			
			if (answer == "y" || answer == "n")
			{
				break;
			}
			else
			{
				cout << "\n\nThat wasn't a valid response! Try again. Enter y for yes or n for no.\n";

				cin >> answer;
			}

		}

	} while (answer == "y");

	return 0;
}