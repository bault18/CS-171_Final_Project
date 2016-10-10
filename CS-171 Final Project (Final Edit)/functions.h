#include <iostream>
using namespace std;


void intro()
{
	cout << "Welcome to hangman!\n\n"
		<< "Please choose a subject below so that we may choose a word for you to guess. \n"
		<< "\t1. Colors\n"
		<< "\t2. Animals\n"
		<< "\t3. School Classes\n"
		<< "\t4. Food\n"
		<< "\t5. Movies\n"
		<< "\t6. Input your own word in for friends to guess\n";
	//insert in a few more subjects
}

void subjectchoice(int& a)
{
	//User chooses subject here
	cout << "\nType in the number next to the subject you want to guess: ";
	int wrongnumber = 0;

	do{
		cin >> a;
		a -= 1;
		wrongnumber = 0;

		if (a < 0 || a > 5)
		{
			wrongnumber += 1;
			cout << "\nInvalid input. Please enter a different subject number: ";
		}

	} while (wrongnumber != 0);
}



void hangman(int a)
{
	switch (a)
	{
	case 0:
		cout << "\t_____________\n";
		cout << "\t    |     \\ |\n";
		cout << "\t           \\|\n";
		cout << "\t            |\n";
		cout << "\t            |\n";
		cout << "\t            |\n";
		cout << "\t            |\n";
		cout << "\t------------|\n";
		break;
	case 1:
		cout << "\t_____________\n";
		cout << "\t    |     \\ |\n";
		cout << "\t    O      \\|\n";
		cout << "\t            |\n";
		cout << "\t            |\n";
		cout << "\t            |\n";
		cout << "\t            |\n";
		cout << "\t------------|\n";
		break;
	case 2:
		cout << "\t_____________\n";
		cout << "\t    |     \\ |\n";
		cout << "\t    O      \\|\n";
		cout << "\t    |       |\n";
		cout << "\t            |\n";
		cout << "\t            |\n";
		cout << "\t            |\n";
		cout << "\t------------|\n";
		break;
	case 3:
		cout << "\t_____________\n";
		cout << "\t    |     \\ |\n";
		cout << "\t    O      \\|\n";
		cout << "\t   /|       |\n";
		cout << "\t            |\n";
		cout << "\t            |\n";
		cout << "\t            |\n";
		cout << "\t------------|\n";
		break;
	case 4:
		cout << "\t_____________\n";
		cout << "\t    |     \\ |\n";
		cout << "\t    O      \\|\n";
		cout << "\t   /|\\      |\n";
		cout << "\t            |\n";
		cout << "\t            |\n";
		cout << "\t            |\n";
		cout << "\t------------|\n";
		break;
	case 5:
		cout << "\t_____________\n";
		cout << "\t    |     \\ |\n";
		cout << "\t    O      \\|\n";
		cout << "\t   /|\\      |\n";
		cout << "\t    |       |\n";
		cout << "\t            |\n";
		cout << "\t            |\n";
		cout << "\t------------|\n";
		break;
	case 6:
		cout << "\t_____________\n";
		cout << "\t    |     \\ |\n";
		cout << "\t    O      \\|\n";
		cout << "\t   /|\\      |\n";
		cout << "\t    |       |\n";
		cout << "\t   /        |\n";
		cout << "\t            |\n";
		cout << "\t------------|\n";
		break;
	}
}


void endgame(int a)
{
	if (a == 7)
	{
		cout << "You killed him =(\n";
		cout << "\t_____________\n";
		cout << "\t    |     \\ |\n";
		cout << "\t    O      \\|\n";
		cout << "\t   /|\\      |\n";
		cout << "\t    |       |\n";
		cout << "\t   / \\      |\n";
		cout << "\t            |\n";
		cout << "\t------------|\n";
	}
	else
	{
		cout << "You saved him!\n";
		cout << "\t_____________\n";
		cout << "\t    |     \\ |\n";
		cout << "\t           \\|       Yayyy!!!\n";
		cout << "\t            |     "; printf("%C", 2); cout << endl;
		cout << "\t            |    \\|/  \n";
		cout << "\t            |     |\n";
		cout << "\t            |    / \\   \n";
		cout << "\t------------|----------\n";

	}
}

void goodbye(){
	system("CLS");
	cout
		<< "\tThanks for playing!\n"
		<< "           "; printf("%C", 2); cout << " /       \\ "; printf("%C", 2); cout << endl
		<< "           |/         \\|\n"
		<< "          /|           |\\ \n"
		<< "          / \\         / \\ \n"
		<< "        Brian    &    Brodie\n";
}