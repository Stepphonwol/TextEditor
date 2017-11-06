#include "Editor.h"

int main(void)
{
	Editor e;
	//e.view();
	while (1) {
		char sign;
		cout << "Press specific buttons for functions you desire, and more specificly, press h for help" << endl;
		cin >> sign;
		cin.get();//!!!!!!!!!!
		if (sign == 'b') {
			e.begin();
		}
		else if (sign == 'g') {
			e.go();
		}
		else if (sign == 'n') {
			e.nex();
		}
		else if (sign == 'p') {
			e.pri();
		}
		else if (sign == 'd') {
			e.del();
		}
		else if (sign == 'v') {
			e.view();
		}
		else if (sign == 'c') {
			e.change();
		}
		else if (sign == 'q') {
			e.quit();
		}
		else if (sign == 'l') {
			e.textlength();
		}
		else if (sign == 'i') {
			e.insert();
		}
		else if (sign == 'e') {
			e.end();
		}
		else if (sign == 's') {
			e.substitude();
		}
		else if (sign == 'f') {
			e.find();
		}
		else if (sign == 'w') {
			e.write();
		}
		else if (sign == 'h') {
			e.help();
		}
		else if (sign == 'a') {
			e.show_line();
		}
		else if (sign == 'r') {
			e.read();
		}
	}
	//e.begin();
	//e.view();

	return 0;
}