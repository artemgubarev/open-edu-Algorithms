#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cmath>
#include <algorithm>


using namespace std;


void insertSort(double(*a), int n) {
	for (int i = 1; i < n; i++) {
		double key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
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

	double *a = new double[n];
	double *buf = new double[n];

	for (int i = 0; i < n; i++) {
		in >> a[i];
		buf[i] = a[i];
	}


	insertSort(a, n);

	out << endl;

	int mid, left, right;

	for (int i = 0; i < n; i++) {
		if (buf[i] == a[0]) left = i;
		if (buf[i] == a[n - 1]) right = i;
		if (buf[i] == a[n / 2]) mid = i;
	}

	out << left + 1 << " " << mid + 1 << " " << right + 1;

	in.close();
	out.close();
}