#include "Style.hpp"




istream& operator>>(istream& in, Style& item)
{
	in >> item.element >> item.attribute >> item.value;
	return in;
}

ostream& operator<<(ostream& out, const Style& item)
{
	out << item.element << "{ " << item.attribute << ": " << item.value << "; }";
	return out;
}

