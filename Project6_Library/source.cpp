//Justin Sitton
//3/20/2016
//Project 6

#include <iostream>
#include <string>
using namespace std;


int checkInput();
bool playGameAgain();
int findSolution(int number, int numberOfMoves);

int main()
{
	bool playGame = true;
	int numberOfMoves = 0;
	int teddyBears = 0;

	while (playGame)
	{
		teddyBears = checkInput();
		cout << "Searching for a solution within 20 moves..." << endl;
		findSolution(teddyBears, numberOfMoves);
		playGame = playGameAgain();
	}
	return 0;
}




int checkInput()
{
	int teddyBears;
	bool invalid = true;
	while (invalid)
	{
		cout << endl;
		cout << "How many bears are you starting with ? ";
		cin >> teddyBears;
		if (teddyBears < 1 || teddyBears > 10000)
		{
			cout << "Number of bears must be greater than 0 and no more than 10000." << endl;
			invalid = true;
		}
		else
		{
			invalid = false;
			return teddyBears;
		}
	}
}


bool playGameAgain()
{
	string playAgain;
	bool run = true;
	while (run)
	{
		cout << "Would you like to try again [Y/N]? ";
		cin >> playAgain;

		if (playAgain == "Y" || playAgain == "y" || playAgain == "yes" || playAgain == "YES")
		{
			return true;
		}
		else if (playAgain == "N" || playAgain == "n" || playAgain == "no" || playAgain == "NO")
		{
			return false;
		}
		else
		{
			cout << "Please enter valid input [Y or N] " << endl;
		}
	}
}




int findSolution(int number, int numberOfMoves)
{
	int oldNumber;
	if (numberOfMoves > 20)
	{
		cout << "No solution found within 20 moves. Sorry." << endl << endl;
		return -1;
	}
	else if (number == 17)
	{
		cout << "Found Solution. I have exactly 17 bears, with " << (20 - numberOfMoves) << " left." << endl << endl;
		return 1;
	}
	else if ((number + 23) % 17 == 0)
	{
		oldNumber = number;
		number += 23;
		cout << "With " << oldNumber << " , add 23 to get " << number << endl;
		return findSolution(number, numberOfMoves + 1);
	}
	else if (number % 2 == 0)
	{
		oldNumber = number;
		number /= 2;
		cout << "Reduce " << oldNumber << " , by a half to get " << number << endl;
		return findSolution(number, numberOfMoves + 1);
	}
	else if (number % 3 == 0)
	{
		oldNumber = number;
		number = number + (number / 3);
		cout << "With " << oldNumber << " , add 1/3 to get " << number << endl;
		return findSolution(number, numberOfMoves + 1);
	}
	else
	{
		oldNumber = number;
		number += 23;
		cout << "With " << oldNumber << " , add 23 to get " << number << endl;
		return findSolution(number, numberOfMoves + 1);
	}
	

}