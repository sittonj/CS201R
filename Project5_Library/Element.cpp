#include "Element.hpp"
#include <iostream>
using namespace std;

IElement::~IElement()
{
	
}

istream& operator>>(istream& in, IElement& item)
{
	return item.Input(in);
}
ostream& operator<<(ostream& out, IElement& item)
{
	item.Output(out);
	return out;
}


//ANCHOR CLASS DEFINITIONS
Anchor::~Anchor()
{

}

ostream& Anchor::Output(ostream& out)
{
	out << "<a href='" << m_href << "'>" << m_text << "</a>";
	return out;
}

istream& Anchor::Input(istream& in)
{
	in >> m_href;
	in.ignore();
	getline(in, m_text);
	return in;
}

//PARAGRAPH CLASS DEFINITIONS
Paragraph::~Paragraph()
{

}

ostream& Paragraph::Output(ostream& out)
{
	out << "<p>" << m_text << "</p>";
	return out;
}

istream& Paragraph::Input(istream& in)
{
	in.ignore();
	getline(in, m_text);
	return in;
}


//HEADER CLASS DEFINITIONS
Header::~Header()
{

}

ostream& Header::Output(ostream& out)
{
	if (m_headerLevel == "size_big")
	{
		out << "<h1>" << m_text << "</h1>";
		return out;
	}
	else if (m_headerLevel == "size_medium")
	{
		out << "<h2>" << m_text << "</h2>";
		return out;
	}
	else
	{
		out << "<h3>" << m_text << "</h3>";
		return out;
	}
	
}

istream& Header::Input(istream& in)
{
	in >> m_headerLevel;
	in.ignore();
	getline(in, m_text);
	return in;
}


//TEXTBOX CLASS DEFINITIONS
Textbox::~Textbox()
{

}

ostream& Textbox::Output(ostream& out)
{
	out << "<input type='text' name='" << m_name << "'>";
	return out;
}

istream& Textbox::Input(istream& in)
{
	in >> m_name;
	return in;
}


//BUTTON CLASS DEFINITIONS
Button::~Button()
{

}

ostream& Button::Output(ostream& out)
{
	out << "<input type='button' name='" << m_name << "' value='" << m_value << "'>";
	return out;
}

istream& Button::Input(istream& in)
{
	in >> m_name;
	in.ignore();
	getline(in, m_value);
	return in;
}