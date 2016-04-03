#ifndef _WEBCREATOR
#define _WEBCREATOR

#include "Style.hpp"
#include "Element.hpp"
#include <vector>
using namespace std;

class WebCreator
{
private:
	vector<Style> m_styleList;
	vector<IElement*> m_elementList;
	string m_title;

	void ReadStyle(const string& stylePage);
	void ReadPage(const string& pagePath);
	void BuildPage(const string& pagePath);

	ostream& OutputHeader(ostream& out);
	ostream& OutputStyle(ostream& out);
	ostream& OutputElement(ostream& out);
	ostream& OutputFooter(ostream& out);

public:
	WebCreator(const string& title);
	~WebCreator();

	void ConvertToHTML(const string& stylePath, const string& pagePath, const string& outputPath);

};


#endif
