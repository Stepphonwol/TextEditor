#include "Editor.h"

Editor::Editor()
{
	cout << "Name of the input txt : ";
	cin >> input_name;
	/*in.open(input_name);
	while (!in) {
		cout << "Invalid input!!!" << endl
			<< "Name of the input txt : " << endl;
		cin >> input_name;
		in.open(input_name);
	}*/
	cout << "Name of the output txt : ";
	cin >> output_name;
	//read();
	//out.open(output_name);
	/*char temp_head[100];
	in.getline(temp_head, 100);
	int num{ 0 };
	String temp_shead(temp_head);
	head = new Line(temp_head, num);
	cur = head;
	while (!in.eof()) {
		in.getline(temp_head, 100);
		String temp_shead(temp_head);
		++num;
		Line* temp_line = new Line(temp_shead, num);
		cur->next = temp_line;
		temp_line->prev = cur;
		cur = temp_line;
	}
	cur = head;
	show_line();
	size = num + 1;
	in.close();*/
}

void Editor::read()
{
	in.open(input_name);
	while (!in) {
		cout << "Invalid input!!!" << endl
		<< "Name of the input txt : " << endl;
		cin >> input_name;
		in.open(input_name);
	}
	char temp_head[100];
	in.getline(temp_head, 100);
	int num{ 0 };
	String temp_shead(temp_head);
	head = new Line(temp_head, num);
	cur = head;
	while (!in.eof()) {
		in.getline(temp_head, 100);
		String temp_shead(temp_head);
		++num;
		Line* temp_line = new Line(temp_shead, num);
		cur->next = temp_line;
		temp_line->prev = cur;
		cur = temp_line;
	}
	cur = head;
	show_line();
	size = num + 1;
	in.close();
}

void Editor::begin()
{
	cur = head;
	cur->show();
}

void Editor::change()
{
	String temp;
	cout << "What segments of the line are you going to change?" << endl;
	cin >> temp;
	cur->alter(temp);
	cur->show();
	//cur = head; // !!!!!!!!!!
}

void Editor::view()
{
	Line* t = head;
	while (t != NULL) {
		t->show();
		t = t->next;
	}
	show_line();
}

void Editor::go()
{
	int choice;
	cout << "Which line do you wanna go to?" << endl;
	cin >> choice;
	if (choice > size - 1 || choice < 0) {
		cout << "Invalid input" << endl;
	}
	else {
		Line*t = head;
		while (t != NULL) {
			if (t->place == choice) {
				cur = t;
				cur->show();
				break;
			}
			t = t->next;
		}
	}
}

void Editor::nex()
{
	if (cur == NULL) {
		cout << "Invalid operation!!!" << endl;
		return;
	}
	if (cur->next == NULL) {
		cout << "You are already at the end of the text." << endl;
		return;
	}
	cur = cur->next;
	cur->show();
}

void Editor::pri()
{
	if (cur == NULL) {
		cout << "Invalid operation!!!" << endl;
		return;
	}
	if (cur->prev == NULL) {
		cout << "You are already at the beginning of the text." << endl;
		return;
	}
	cur = cur->prev;
	cur->show();
}

void Editor::del()
{
	Line* temp = cur;
	if (cur == head) {
		head = head->next;
		--size;
		recount();
		delete temp;
	}
	else {
		temp->prev->next = temp->next;
		--size;
		recount();
		delete temp;
	}
	cur = head;
	cur->show();
}

void Editor::recount()
{
	int num{ 0 };
	Line* t = head;
	while (t != NULL) {
		t->place = num;
		++num;
		t = t->next;
	}
}

void Editor::textlength()
{
	cout << "There are " << size << " lines in the text" << endl
		<< "The current line has " << cur->text.length << " words" << endl;
}

void Editor::insert()
{
	int n, i{ 0 };
	cout << "Type in the index of the line you wanna insert : " << endl;
	cin >> n;
	cin.get();//!!!!!!!!!!
	cur = head;
	while (cur->place != n) {
		cur = cur->next;
	}
	String buffer_s;
	cout << "Type in the new line you wanna insert : " << endl;
	cin >> buffer_s;
	Line* buffer_line = new Line(buffer_s, n);
	buffer_line->next = cur;
	buffer_line->prev = cur->prev;
	cur->prev->next = buffer_line;
	cur->prev = buffer_line;
	++size;
	recount();
	cur = buffer_line;
	cur->show();
}

void Editor::end()
{
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->show();
}

void Editor::find()
{
	int i{ 0 };
	cout << "Type in the word you wanna search : " << endl;
	String buffer_search;
	cin >> buffer_search;
	while (cur->text.source[i] != '\0') {
		if (cur->text.source[i] == buffer_search.source[0]) {
			int temp{ i }, j{ 0 };
			while (j < buffer_search.length){
				if (cur->text.source[i] == buffer_search.source[j]) {
					++j;
					++i;
				}
				else {
					break;
				}
			}
			i = temp;
			if (j == buffer_search.length) {
				char temp_out[100] = { '0' };
				for (int k = i + 3; k < i + j + 3; ++k) {
					temp_out[k] = '^';
				}
				cur->show();
				for (int k = 0; k < i + j + 3; ++k) {
					if (temp_out[k] != '0') {
						cout << temp_out[k];
					}
				}
				return;
			}
		}
		++i;
	}
	cout << "No strings were found !!!" << endl;
	//cout << "No strings were found!!!" << endl;
}

void Editor::substitude()
{
	int n;
	cout << "Which line do you wanna substitude ?" << endl;
	cin >> n;
	cin.get();
	cur = head;
	while (cur->place != n) {
		cur = cur->next;
	}
	Line* temp = cur;
	String buffer_s;
	cout << "Type in the new line you wanna change into : " << endl;
	cin >> buffer_s;
	Line* buffer_line = new Line(buffer_s, n);
	buffer_line->next = cur->next;
	buffer_line->prev = cur->prev;
	cur->prev->next = buffer_line;
	cur->next->prev = buffer_line;
	cur = buffer_line;
	delete temp;
	recount();
	cur->show();
}

void Editor::write()
{
	cur = head;
	out.open(output_name, ios::out);
	while (!out) {
		cout << "Invalid output!!!" << endl
			<< "Name of the output txt : " << endl;
	}
	while (cur != NULL) {
		out << cur->text.source;
		out << endl;
		cur = cur->next;
	}
	cur = head;
	out.close();
	cout << "Changes saved!" << endl;
	delete head;
	//delete cur;
	//read();
}

void Editor::show_line()
{
	cout << "You are now in : " << cur->place << " line" << endl;
}

void Editor::help()
{
	cout << "b(egin), c(hange), v(iew), g(o), q(uit), n(ext), p(revious), d(elete), l(ength), i(nsert), e(nd), f(ind)" << endl
		<< "s(ubstitude), w(rite), a(bouts), h(elp)" << endl;
}

void Editor::quit()
{
	exit(0);
}