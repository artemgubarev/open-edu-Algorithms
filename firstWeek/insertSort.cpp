#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cmath>
#include <algorithm>


using namespace std;


void insertSort(int *a, int *b, int n) {

	for (int i = 1; i < n; i++) {
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		b[i] = j + 2;
		a[j + 1] = key;
	}
}


int main() {
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");

	int n;
	in >> n;

	int *a = new int[n];
	int *b = new int[n];

	for (int i = 0; i < n; i++) {
		in >> a[i];
	}


	insertSort(a, b, n);

	b[0] = 1;

	for (int i = 0; i < n; i++) {
		out << b[i] << " ";
	}

	out << endl;

	for (int i = 0; i < n; i++) {
		out << a[i] << " ";
	}


	in.close();
	out.close();
}