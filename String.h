#pragma once
#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <fstream>

using namespace std;

class Line;
class Editor;

class String {
	friend class Line;
	friend class Editor;
	friend istream& operator>>(istream& is, String& s);
	friend ostream& operator<<(ostream& os, String s);
	private:
		String(char* s = NULL) {
			int i{ 0 };
			while (s != NULL && s[i] != '\0') {
				++i;
			}
			source = new char[i];
			i = 0;
			while (s != NULL && s[i] != '\0') {
				source[i] = s[i];
				++i;
			}
			source[i] = '\0';
			length = i;
		}
		~String() {
			//delete source;
		}
		String operator=(String& x);
		char* source;
		int length{ 0 };
};
#endif