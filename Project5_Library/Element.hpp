#ifndef _ELEMENT
#define _ELEMENT

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class IElement
{
public:
	~IElement();
	friend istream& operator>>(istream& in, IElement& item);
	friend ostream& operator<<(ostream& out, IElement& item);

protected:
	virtual ostream& Output(ostream& out) = 0;
	virtual istream& Input(istream& in) = 0;
};





class Anchor : public IElement
{
public:
	virtual ~Anchor();
	virtual ostream& Output(ostream& out);
	virtual istream& Input(istream& in);

private:
	string m_href;
	string m_text;
};


class Paragraph : public IElement
{
public:
	virtual ~Paragraph();
	virtual ostream& Output(ostream& out);
	virtual istream& Input(istream& in);

private:
	string m_text;
};


class Header : public IElement
{
public:
	virtual ~Header();
	virtual ostream& Output(ostream& out);
	virtual istream& Input(istream& in);

private:
	string m_text;
	string m_headerLevel;
};


class Textbox : public IElement
{
public:
	virtual ~Textbox();
	virtual ostream& Output(ostream& out);
	virtual istream& Input(istream& in);

private:
	string m_name;
};

class Button : public IElement
{
public:
	virtual ~Button();
	virtual ostream& Output(ostream& out);
	virtual istream& Input(istream& in);

private:
	string m_name;
	string m_value;
};
#endif