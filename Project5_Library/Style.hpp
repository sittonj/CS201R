#ifndef _STYLE
#define _STYLE

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Style
{
public:
	string element;
	string attribute;
	string value;

	friend istream& operator>>(istream& in, Style& item);
	friend ostream& operator<<(ostream& out, const Style& item);
	
};

#endif