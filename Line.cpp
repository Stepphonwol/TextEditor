#include "Line.h"

void Line::show()
{
	cout << place << " " << text << endl;
}

void Line::alter(String s)
{
	int i{ 0 };
	while(text.source[i] != '\0') {
		if (text.source[i] == s.source[0]) {
			int temp = i, j{ 0 };
			while (j < s.length) {
				if (s.source[j] == text.source[i]) {
					++j;
					++i;
				}
				else {
					break;
				}
			}
			i = temp;
			if (j == s.length) { // j : length of the segment which needs to be changed
				String input;
				int diff{ 0 };
				cout << "Type in the words you wanna substitude:" << endl;
				cin >> input;
				if (j > input.length) {
					diff = j - input.length;
					for (int t = i + j; t < text.length; ++t) {
						text.source[t - diff] = text.source[t];
					}
					text.source[text.length - diff] = '\0';
					text.length -= diff;
					for (int k = 0; k < input.length; ++k) {
						text.source[i] = input.source[k];
						++i;
					}
				}
				else if (j < input.length) {
					diff = input.length - j;
					for (int t = text.length - 1; t >= i + j; --t) {
						text.source[t + diff] = text.source[t];
					}
					text.source[text.length + diff] = '\0';
					text.length += diff;
					for (int k = 0; k < input.length; ++k) {
						text.source[i] = input.source[k];
						++i;
					}
				}
				else if (j == input.length) {
					for (int k = 0; k < input.length; ++k) {
						text.source[i] = input.source[k];
						++i;
					}
				}
				return;
			}
		}
		++i;
	}
	cout << "No strings were found !!!" << endl;
}