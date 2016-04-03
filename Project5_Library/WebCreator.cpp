#include "WebCreator.hpp"

WebCreator::WebCreator(const string& title)
{
	m_title = title;
}

WebCreator::~WebCreator()
{
	for (int i = 0; i < m_elementList.size(); i++)
	{
		delete m_elementList[i];
		m_elementList[i] = NULL;
	}
}

void WebCreator::ConvertToHTML(const string& stylePath, const string& pagePath, const string& outputPath)
{
	ReadStyle(stylePath);
	ReadPage(pagePath);
	BuildPage(outputPath);
}



void WebCreator::ReadStyle(const string& stylePage)
{
	ifstream styleIn(stylePage);
	Style object;

	while (styleIn.good())
	{
		styleIn >> object;
		m_styleList.push_back(object);
	}
	
	styleIn.close();
}

void WebCreator::ReadPage(const string& pagePath)
{
	ifstream pageIn(pagePath);
	string label;


	while (pageIn.good())
	{
		pageIn >> label;
		IElement* element;
		element = NULL;
		
		if (label == "HEADER")
		{
			element = new Header;
			pageIn >> *element;
			m_elementList.push_back(element);
		}
		else if (label == "PARAGRAPH")
		{
			element = new Paragraph;
			pageIn >> *element;
			m_elementList.push_back(element);
		}
		else if (label == "LINK")
		{
			element = new Anchor;
			pageIn >> *element;
			m_elementList.push_back(element);
		}
		else if (label == "TEXTBOX")
		{
			element = new Textbox;
			pageIn >> *element;
			m_elementList.push_back(element);
		}
		else if (label == "BUTTON")
		{
			element = new Button;
			pageIn >> *element;
			m_elementList.push_back(element);
		}
	}
	pageIn.close();
}

void WebCreator::BuildPage(const string& pagePath)
{
	ofstream OutputPage(pagePath);
	OutputHeader(OutputPage);
	OutputStyle(OutputPage);
	OutputElement(OutputPage);
	OutputFooter(OutputPage);
	OutputPage.close();
}



ostream& WebCreator::OutputHeader(ostream& out)
{
	{
		out << "<!DOCTYPE html><html>" << endl
			<< "<head>" << endl
			<< "<title>" << m_title << "</title>" << endl
			<< "</head><body>" << endl;
		return out;
	}}

ostream& WebCreator::OutputStyle(ostream& out)
{
	{
		out << "<style type='text/css'>" << endl;
		for (int i = 0; i < m_styleList.size(); i++)
		{
			out << m_styleList[i] << endl << endl;
		}
		out << "</style>" << endl;
		return out;
	}}


ostream& WebCreator::OutputElement(ostream& out)
{
	for (int i = 0; i < m_elementList.size(); i++)
	{
		out << *m_elementList[i] << endl;
	}
	return out;
}


ostream& WebCreator::OutputFooter(ostream& out)
{
	out << endl << "</body></html>" << endl;
	return out;
}