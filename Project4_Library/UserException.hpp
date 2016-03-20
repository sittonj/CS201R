#ifndef _USEREXCEPTION
#define _USEREXCEPTION
#include <string>
using namespace std;

class UserException
{

private:
	string m_message;


public:
	UserException(const string& message);
	string What() const;

};


#endif
