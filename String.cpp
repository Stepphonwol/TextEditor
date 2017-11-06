#include "String.h"

istream& operator>>(istream& is, String& s)
{
	char t[100];
	int i{ 0 };
	is.getline(t, 100);
	String temp(t);
	s = temp;

	return is;
}

ostream& operator<<(ostream& os, String s)
{
	for (int i = 0; i < s.length; ++i) {
		os << s.source[i];
	}
	os << endl;

	return os;
}

String String::operator=(String& x)
{
	int i{ 0 };
	this->source = new char(x.length);
	while (x.source[i] != '\0') {
		this->source[i] = x.source[i];
		++i;
	}
	this->source[i] = '\0';
	this->length = i;

	return this->source;

}