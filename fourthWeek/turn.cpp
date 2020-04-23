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

	int *turn = new int[n];

	char ch;
	int top = 0;
	int j = 0;

	while (in.get(ch)) {
		if (ch == '+') {
			in >> turn[j];
			j++;
		}

		if (ch == '-') {
			out << turn[top] << endl;
			top++;
		}
	}

	delete[] turn;


	out.close();
	in.close();
}