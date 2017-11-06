#pragma once
#ifndef EDITOR_H
#define EDITOR_H
#include "Line.h"

class Editor {
	public:
		Editor();
		~Editor() {
			//delete head;
			//delete cur;
		}
		void begin();
		void change();
		void view();
		void go();
		void quit();
		void nex();
		void pri();
		void del();
		void textlength();
		void insert();
		void end();
		void find();
		void substitude();
		void write();
		void show_line();
		void help();
		void read();
	private:
		Line* head;
		Line* cur;
		ifstream in;
		ofstream out;
		int size;
		char input_name[100];
		char output_name[100];
		void recount(); // used after deleting or inserting a line in the text, and all the indexs need to be modified
};
#endif
