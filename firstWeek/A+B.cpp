// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");

	int a, b;

	in >> a >> b;

	out << a + b;

	in.close();
	out.close();
}