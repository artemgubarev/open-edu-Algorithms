#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;


int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n;
	in >> n;

	string *str = new string[n];

	for (int i = 0; i < n; i++) {
		in >> str[i];
	}

	for (int i = 0; i < n; i++) {
		char *stack = new char[str[i].size()];
		bool valid = true;
		int top = -1;
		for (int j = 0; j < str[i].size(); j++) {
			if (str[i][j] == '(') {
				top++;
				stack[top] = '(';
			}
			if (str[i][j] == '[') {
				top++;
				stack[top] = '[';
			}
			if (str[i][j] == ')') {
				if (stack[top] == '(') top--;
				else {
					valid = false;
					break;
				}
			}
			if (str[i][j] == ']') {
				if (stack[top] == '[') top--;
				else {
					valid = false;
					break;
				}
			}
		}

		if (top != -1 || !valid) out << "NO" << endl;
		else out << "YES" << endl;
	}

	out.close();
	in.close();
}