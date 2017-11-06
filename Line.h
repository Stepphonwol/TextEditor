#pragma once
#ifndef LINE_H
#define LINE_H
#include "String.h"

class Editor;

class Line {
	friend class Editor;
	private:
		Line(String s, int p) : text(s), place(p), prev(NULL), next(NULL) {}
		~Line() {
			;
		}
		void show();
		void alter(String s);
		String text;
		int place;
		Line* prev;
		Line* next;
};
#endif