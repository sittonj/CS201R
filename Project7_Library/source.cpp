//Justin Sitton
//4/30/2016
//Project 7

#include "Queue.hpp"
#include "Queue.cpp"

#include <fstream>
#include <string>
#include <iostream>
#include <map>
using namespace std;

void InsertionSort(Queue<ProblemInformation> arr[], int size)
{
	int j;
	for (int p = 1; p < size; p++)
	{
		int correct = arr[p].get_numberCorrect();
		int teamNum = arr[p].get_teamNumber();
		int score = arr[p].get_score();

		for (j = p; j > 0 && correct > arr[j - 1].get_numberCorrect(); j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j].set_numberCorrect(correct);
		arr[j].set_teamNumber(teamNum);
		arr[j].set_score(score);
	}

}



int main()
{

	Queue<ProblemInformation> Teams[30];

	ifstream fin("Data_01.csv");
	ofstream foutT("Teams.txt");
	ofstream foutR("Rankings.txt");

	int time;
	int teamNum;
	char problem;
	string language;
	string result;
	string feedback;

	while (fin>>time)
	{
		fin >> teamNum;
		fin >> problem;
		fin >> language;
		fin >> result;
		getline(fin, feedback);

		Teams[teamNum - 1].set_problemResult(teamNum, time, problem, language, result, feedback);
		Teams[teamNum - 1].push_back();
	}

	for (int i = 0; i < 30; i++)
	{
		cout << "Team " << Teams[i].get_teamNumber() << " solved " << Teams[i].get_numberCorrect() << " for a score of " << Teams[i].get_score() << endl;
	}

	cout << endl;
	Teams[1].display_attempts();
	cout << endl;
	cout << endl;


	InsertionSort(Teams, 30);

	cout << "INSERTION SORT" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << "Team " << Teams[i].get_teamNumber() << " solved " << Teams[i].get_numberCorrect() << " for a score of " << Teams[i].get_score() << endl;
	}
	
	cout << endl;
	Teams[1].display_attempts();
	

	
	fin.close();
	foutR.close();
	foutT.close();
	return 0;
}