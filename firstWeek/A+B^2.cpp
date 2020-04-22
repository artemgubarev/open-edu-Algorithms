#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");


	int64_t a, b;

	in >> a >> b;
	out << a + b * b;


	in.close();
	out.close();
}