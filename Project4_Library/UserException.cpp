#include "UserException.hpp"

UserException::UserException(const string& message)
{
	m_message = message;
}

string UserException::What() const
{
	return m_message;
}