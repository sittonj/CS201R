#include "User.hpp"
#include "UserException.hpp"

User::User()
{
	m_id = 0;
	m_firstName = " ";
	m_lastName = " ";
	m_borrowedBooksList = NULL;
	m_arraySize = 0;
	m_borrowedCount = 0;
}

User::User(unsigned int id = 0, string firstName = " ", string lastName = " ")
{
	m_id = id;
	m_firstName = firstName;
	m_lastName = lastName;
	m_borrowedBooksList = NULL;
	m_arraySize = 0;
	m_borrowedCount = 0;
}

User::~User()
{
	if (m_borrowedBooksList != NULL)
	{
		delete[] m_borrowedBooksList;
		m_borrowedBooksList = NULL;
	}
}

//Functions

bool User::HasCheckedOut(const string& bookId) const
{
	if (m_borrowedBooksList != NULL)
	{
		for (unsigned int i = 0; i < m_arraySize; i++)
		{
			if (bookId == m_borrowedBooksList[i])
			{
				return true;
			}
		}
	}
	return false;
}

unsigned int User::CheckoutCount() const
{
	return m_borrowedCount;
}


bool User::CheckOut(const string& bookId)
{
	bool resized;
	bool checkedOut = HasCheckedOut(bookId);
	if (checkedOut == true)
	{
		return false;
	}
	else
	{
		if (m_borrowedBooksList == NULL)
		{
			createList();
		}
		else if (m_borrowedCount == m_arraySize)
		{
			{
				resized = resizeArray();
				if (resized == false)
				{
					return false;
				}
			}
		}
		m_borrowedBooksList[m_borrowedCount] = bookId;
		m_borrowedCount += 1;
	}
}

bool User::CheckIn(const string& bookId)
{
	int lastBookInArray = m_borrowedCount - 1;
	
	for (unsigned int i = 0; i < m_arraySize; i++)
	{
		try
		{
			if (bookId == m_borrowedBooksList[i])
			{
				m_borrowedBooksList[i] = m_borrowedBooksList[lastBookInArray];
				m_borrowedBooksList[lastBookInArray] = " ";
				m_arraySize -= 1;
				m_borrowedCount -= 1;

				if (m_arraySize == 0)
				{
					destroyList();
				}
				else
				{
					return resizeArray();
				}
			}
		}
		catch (UserException e)
		{
			cerr << "Error: Book was not checked out!" << e.What() << endl;
		}
	}
}


// Getters and Setters
unsigned int User::GetID() const
{
	return m_id;
}

string User::GetFirstName() const
{
	return m_firstName;
}

string User::GetLastName() const
{
	return m_lastName;
}

string User::GetFullName() const
{
	string fullName =  m_lastName + ", " + m_firstName;
	return fullName;
}

void User::SetFirstName(const string& first)
{
	m_firstName = first;
}

void User::SetLastName(const string& last)
{
	m_lastName = last;
}

void User::SetID(unsigned int id)
{
	if (id >= 100 && id <= 1000000)
	{
		m_id = id;
	}
	else
	{
		m_id = 0;
	}
}


// Operation Overloads
bool operator==(const User& item, const User& rhs) 
{
	return item.GetFullName() == rhs.GetFullName();
}

const User operator+(const User& UserID, const string& rhs)
{
	User User2 = UserID;
	User2.CheckOut(rhs);
	return User2;
}

void operator+=(User& UserID, const string& rhs)
{
	UserID.CheckOut(rhs);
}

ostream& operator<<(ostream& out, const User& UserID)
{
	out << "ID: " << UserID.GetID() << endl;
	out << "\t Name " << UserID.GetFirstName() << " " << UserID.GetLastName() << endl;
	out << "\t Book_Count: " << UserID.CheckoutCount() << endl;
	
	for (unsigned int i = 0; i < UserID.m_borrowedCount; i++)
	{
		out << "\t\t" << UserID.m_borrowedBooksList[i] << endl;
	}

	out << "END" << endl << endl;
	return out;
}

istream& operator>>(istream& in, User& item)
{
	unsigned int numOfBooks;
	string buffer;
	string book;

	in >> buffer >> item.m_id >> buffer >> item.m_firstName >> item.m_lastName >> buffer >> numOfBooks;

	for (unsigned int i = 0; i < numOfBooks; i++)
	{
		in >> book;
		item += book;
	}

	in >> buffer;

	return in;
}

User& User::operator=(const User&rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	m_id = rhs.m_id;
	m_firstName = rhs.m_firstName;
	m_lastName = rhs.m_lastName;
	m_borrowedCount = rhs.m_borrowedCount;

	if (m_arraySize < rhs.m_arraySize)
	{
		resizeArray();
	}
	m_arraySize = rhs.m_arraySize;
	for (unsigned int i = 0; i < m_arraySize; i++)
	{
		m_borrowedBooksList[i] = rhs.m_borrowedBooksList[i];
	}
}

// Management functions
void User::createList()
{
	try
	{
		m_borrowedCount = 0;
		m_arraySize = 5;
		m_borrowedBooksList = new string[m_arraySize];
	}
	catch(UserException e)
	{
		cerr << "Can't get memory for creating a new list, see createList():" << e.What() << endl;
		m_borrowedBooksList = NULL;
		m_borrowedCount = 0;
		m_arraySize = 0;
	}

}

void User::destroyList()
{
	delete[] m_borrowedBooksList;
	m_borrowedBooksList = NULL;
	m_arraySize = 0;
	m_borrowedCount = 0;
}

bool User::resizeArray()
{
	int increasedSize;
	increasedSize = m_arraySize * 2;
	string* tempArray = new string[increasedSize];

	try
	{
		for (unsigned int i = 0; i < m_arraySize; i++)
		{
			tempArray[i] = m_borrowedBooksList[i];
		}
	}
	catch (UserException e)
	{
		cerr << "Error allocating memory: Couldn't Resize the Array:" << e.What() << endl;
	}

	delete[] m_borrowedBooksList;
	m_borrowedBooksList = tempArray;

	tempArray = NULL;

	m_arraySize = increasedSize;
	return true;
}

void User::clear()
{
	m_id = 0;
	m_firstName = " ";
	m_lastName = " ";
	m_arraySize = 0;
	m_borrowedCount = 0;

	if (m_borrowedBooksList != NULL)
	{
		delete[] m_borrowedBooksList;
		m_borrowedBooksList = NULL;
	}
}