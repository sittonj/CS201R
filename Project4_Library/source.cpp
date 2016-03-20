#include "User.hpp"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	string buffer;
	unsigned int numOfUsers;

	ifstream UsersFin("users.txt");
	ifstream CheckOutFin("checkouts.txt");
	ifstream CheckInFin("checkins.txt");

	ofstream outFile("output_dupes.txt");
	ofstream CheckOutFOut("Output.txt");


	UsersFin >> buffer;
	UsersFin >> numOfUsers;

	//Readin data
	User* members = new User[numOfUsers];

	for (unsigned int i = 0; i < numOfUsers; i++)
	{
		UsersFin >> members[i];
	}


	//Check Duplicates
	for (unsigned int user1 = 0; user1 < numOfUsers; user1++)
	{
		for (unsigned int user2 = 1; user2 < numOfUsers; user2++)
		{
			if (members[user1] == members[user2])
			{   
				outFile << "User: " << members[user1].GetFullName() << " has duplicates at IDs " << members[user1].GetID() << " and " << members[user2].GetID() << endl << endl;
			}
		}
	}

	
	//Read in Checkouts file
	unsigned int tempID;
	string tempBook;

	while (CheckOutFin.good())
	{
		CheckOutFin >> buffer >> buffer;
		CheckOutFin >> tempID >> tempBook;

		for (unsigned int findUser = 0; findUser < numOfUsers; findUser++)
		{
			if (tempID == members[findUser].GetID())
			{
				members[findUser].CheckOut(tempBook);
			}
		}
	}


	//Read in Returned Books
	bool checkedOut;
	cout << "CHECKING IN BOOKS" << endl;
	CheckInFin >> buffer;
	while (CheckInFin.good())
	{
		CheckInFin >> tempBook;

		for (unsigned int findUser = 0; findUser < numOfUsers; findUser++)
		{
			checkedOut = members[findUser].HasCheckedOut(tempBook);
			if (checkedOut == true)
			{
				members[findUser].CheckIn(tempBook);
			}
		}

	}


	//Users after all books returned
	for (unsigned int i = 0; i < numOfUsers; i++)
	{
		CheckOutFOut << members[i] << endl;
	}

	delete[] members;

	UsersFin.close();
	CheckOutFin.close();
	CheckOutFin.close();
	CheckOutFOut.close();

	return 0;
}