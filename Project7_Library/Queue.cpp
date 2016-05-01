#include "Queue.hpp"


template <class T>
Queue<T>::Queue()
{
	m_score = 0;
	m_numberCorrect = 0;
	m_teamNumber = 0;
}

template<class T>
void Queue<T>::set_time(int time)
{
	Problem.time = time;
}

template<class T>
void Queue<T>::set_problemLetter(char problem)
{
	Problem.problemLetter = problem;
}

template<class T>
void Queue<T>::set_language(string language)
{
	Problem.language = language;
}

template<class T>
void Queue<T>::set_result(string result, char problem)
{
	Problem.result = result;
	if (result == "Yes")
	{
		m_numberCorrect++;
		Problem.problemsCorrect.push_back(problem);
	}
}

template<class T>
void Queue<T>::set_feedback(string feedback)
{
	Problem.feedback = feedback;
}

template<class T>
void Queue<T>::set_problemResult(int team_number, int time, char problem, string language, string result, string feedback)
{
	m_teamNumber = team_number;
	Problem.time = time;
	Problem.problemLetter = problem;
	Problem.language = language;
	Problem.result = result;
	Problem.feedback = feedback;

	if (result == "Yes")
	{
		m_numberCorrect++;
		Problem.problemsCorrect.push_back(problem);
	}
}

template<class T>
void Queue<T>::set_numberCorrect(int correct)
{
	m_numberCorrect = correct;
}

template<class T>
void Queue<T>::set_teamNumber(int team_number)
{
	m_teamNumber = team_number;
}

template<class T>
void Queue<T>::set_score(int score)
{
	m_score = score;
}

template<class T>
void Queue<T>::push_back()
{
	TeamResults.push_back(Problem);
}

template<class T>
void Queue<T>::display_attempts()
{
	for (list<T>::iterator TR = TeamResults.begin(); TR != TeamResults.end(); TR++)
	{
		cout << TR->problemLetter << " " << TR->time << " " << TR->result << endl;
	}
}

template<class T>
int Queue<T>::calculate_score()
{
	int score = 0;
	for (int i = 0; i < Problem.problemsCorrect.size(); i++)
	{
		int attempt_count = 0;
		for (list<T>::iterator TR = TeamResults.begin(); TR != TeamResults.end(); TR++)
		{
			if (Problem.problemsCorrect[i] == TR->problemLetter && TR->result == "No")
			{
				attempt_count++;
				score += 20;
			}
			else if (Problem.problemsCorrect[i] == TR->problemLetter && TR->result == "Yes")
			{
				score += TR->time;
				attempt_count++;
			}
		}
	}
	return score;
}

template<class T>
int Queue<T>::get_score()
{
	m_score = calculate_score();
	return m_score;
}

template<class T>
int Queue<T>::get_numberCorrect()
{
	return m_numberCorrect;
}

template<class T>
int Queue<T>::get_teamNumber()
{
	return m_teamNumber;
}

