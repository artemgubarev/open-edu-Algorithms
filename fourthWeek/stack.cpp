#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>



using namespace std;



int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n;
	in >> n;

	int *stack = new int[n];

	char ch;
	int top = 0;

	while (in.get(ch)) {
		if (ch == '+') {
			in >> stack[top];
			top++;
		}

		if (ch == '-') {
			out << stack[top - 1] << endl;
			top--;
		}
	}

	delete[] stack;

	out.close();
	in.close();
}