// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;


void generate(int *a, int n) {
	if (n == 1) {
		a[0] = 1;
	}
	if (n > 1) {
		a[0] = 1;
		a[1] = 2;
	}

	for (int i = 3; i <= n; ++i) {
		int key = (i - 1)/2;
		int buf = a[key];
		a[key] = i;
		a[i - 1] = buf;
	}
}

int main()
{
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");

	int n;
	in >> n;
	int *a = new int[n];
	generate(a, n);
	for (int i = 0; i < n; i++) {
		out << a[i] << " ";
	}
	out.close();
	in.close();
}

