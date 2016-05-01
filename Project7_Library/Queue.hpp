#ifndef _QUEUE
#define _QUEUE

#include <list>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class Queue
{
public:
	Queue();

	void set_time(int time);

	void set_problemLetter(char problem);

	void set_language(string language);

	void set_result(string result, char problem);

	void set_feedback(string feedback);

	void set_problemResult(int team_number, int time, char problem, string language, string result, string feedback);

	void set_numberCorrect(int correct);

	void set_teamNumber(int team_number);

	void set_score(int score);

	void push_back();

	void display_attempts();

	int get_score();

	int get_numberCorrect();

	int get_teamNumber();


private:
	list<T> TeamResults;

	T Problem;

	int m_score;
	int m_numberCorrect;
	int m_teamNumber;

	int calculate_score();

};


struct ProblemInformation
{
	int time;
	char problemLetter;
	vector<char>problemsCorrect;
	string language;
	string result;
	string feedback;
};



#endif