#ifndef _USER
#define _USER

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class User
{
private:
	unsigned int m_id;
	unsigned int m_borrowedCount;
	unsigned int m_arraySize;
	string m_firstName;
	string m_lastName;
	string* m_borrowedBooksList;

	bool resizeArray();

public:
	User();
	User(unsigned int id, string firstName, string lastName);
	~User();

	bool HasCheckedOut(const string& bookId) const;
	unsigned int CheckoutCount() const;
	bool CheckOut(const string& bookId);
	bool CheckIn(const string& bookId);

	unsigned int GetID() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetFullName() const;
	void SetFirstName(const string& first);
	void SetLastName(const string& last);
	void SetID(unsigned int id);

	friend bool operator==(const User& item, const User& rhs);
	friend const User operator+(const User& UserID, const string& rhs);
	friend void operator+=(const User& UserID, const string& rhs);
	friend ostream& operator<<(ostream& out, const User& item);
	friend istream& operator>>(istream& out, User& item);

	void createList();
	void destroyList();
	void clear();
};

#endif