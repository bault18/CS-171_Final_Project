#include <iostream>
#include <ctime>
#include <string>
#include "functions.h"
using namespace std;

void intro();
void subjectchoice(int& a);
void hangman(int a);
void endgame(int a);
void goodbye();


int main()
{
	char retry;

	//loop lets you re-run program
	do{
		//clears screen
		system("CLS");

		intro();

		//Variables
		int subject;
		string userinput;

		//let user input subject
		subjectchoice(subject);



		//declaration of words that will exist
		int const wordspersubject = 6, totalsubjects = 6;
		string wordbank[totalsubjects][wordspersubject] = {
			//1. colors
			{ "midnight blue", "crimson red", "green", "purple", "brown", "black" },

			//2. animals
			{ "bengal tiger", "komodo dragon", "leopard", "penguin", "crocodile", "hippopotamus" },

			//3. school classes
			{ "calculus", "biology", "chemistry", "jogging", "microbiology", "thermochemistry" },

			//4. food
			{ "cheeseburger", "hotdog", "sandwich", "chicken and waffles", "freedom fries", "newyork ribeye steak" },

			//5. Movies
			{ "hunger games", "the avengers", "the wolf of wall street", "lone survivor", "twelve years a slave", "the secret life of walter mitty" }

			//6. User input      
		};

		//user input
		if (subject == 5)
		{
			cout << "\n\nPlease type a word or short phrase: ";
			cin.ignore();
			getline(cin, userinput, '\n');
			//puts user input into whole row of array
			for (int i = 0; i < wordspersubject; i++)
			{
				wordbank[5][i] = userinput;
			}
		}

		//Random word generator
		srand(time(NULL));
		int randomword = rand() % 6;


		//Tests for how many letters there are in the word
		int totalchar = wordbank[subject][randomword].length();



		//sets all letters in word to lowercase
		for (int i = 0; i < totalchar; i++)
		{
			if (isalpha(wordbank[subject][randomword].at(i)))
			{
				wordbank[subject][randomword].at(i) = static_cast<char>(tolower(wordbank[subject][randomword].at(i)));
			}
		}



		//Variables
		char guess;
		int const size = 50;
		int correctchars = 0;
		int whitespacechars = 0;
		string correct[size];
		string incorrectguess[size];

		//Displays how many chars the word has
		for (int i = 0; i < totalchar; i++)
		{
			if (isspace(wordbank[subject][randomword].at(i)))
			{
				correct[i] = "  ";
				whitespacechars += 1;
			}
			else
				correct[i] = " _ ";
		}
		//user cannot guess a white space
		correctchars += whitespacechars;

		cout << "Total chars: " << totalchar << endl;
		cout << "Word: " << wordbank[subject][randomword];

		//controls loop of game
		int triesleft = 0;
		do{
			//clears screen of previous text
			system("CLS");

			int correctguess = 0;


			cout << "\n\tIncorrect guesses left: " << 7 - triesleft << endl;

			hangman(triesleft);

			cout << "Answer: ";
			for (int i = 0; i < totalchar; i++)
			{
				cout << correct[i];
			}
			cout << endl;
			cout << "Incorrect: ";

			for (int i = 0; i < triesleft; i++)
			{
				cout << incorrectguess[i] << ", ";
			}



			//user guesses a letter
			do{


				cout << "\nGuess a letter: ";
				cin >> guess;

				if (isdigit(guess))
				{
					cout << "Incorrect input. Please put a character.\n";
				}
			} while (0 != isdigit(guess));

			if (isupper(guess))
			{
				guess = static_cast<char>(tolower(guess));
			}

			cout << endl << endl;

			// Loop will test every letter in the string to see if you entered something correct or not
			for (int i = 0; i < totalchar; i++)
			{
				if (guess == correct[i].at(0))
				{

					correctguess += 1;
				}
				else if (guess == wordbank[subject][randomword].at(i))
				{
					correct[i] = guess;
					correctguess += 1;
					correctchars += 1;
				}
			}
			//displays array with correct guesses
			for (int i = 0; i < triesleft; i++)
			{
				if (guess == incorrectguess[i].at(0))
					correctguess += 1;
			}

			if (correctguess == 0)
			{
				incorrectguess[triesleft] = guess;
				triesleft += 1;
			}

		} while (triesleft < 7 && totalchar != correctchars);

		//clears screen
		system("CLS");

		cout << "The word/phrase was: " << wordbank[subject][randomword] << endl << endl;
		endgame(triesleft);

		//Prompts the user for a retry
		cout << "Would you like to play again? (y/n): ";
		//Loop to test if the user would like a retry

		do{
			cin >> retry;

			if (isdigit(retry))
			{
				cout << "Incorrect input. Please put either 'y' or 'n'.\n";
			}

		} while (0 != isdigit(retry));

		if (isupper(retry))
		{
			retry = static_cast<char>(tolower(retry));
		}

	} while (retry == 'y');

	goodbye();
}