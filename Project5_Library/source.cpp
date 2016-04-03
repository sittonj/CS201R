//Justin Sitton
//3/20/2016
//Project 5

#include "Style.hpp"
#include <fstream>
#include "WebCreator.hpp"

int main()
{

	WebCreator Webpage("C++ WEBPAGE");
	Webpage.ConvertToHTML("sample_style.style", "sample_page.page", "CPPwebpageOutput.html");
	return 0;
}