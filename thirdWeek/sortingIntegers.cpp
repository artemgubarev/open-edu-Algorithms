#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;



int digit(int d, int i) {
	int c = 0;
	int divi = 1;
	int buf = 0;
	while (c <= i) {
		buf = d / divi % 131072;
		c++;
		divi *= 131072;
	}
	return buf;
}
void radixSort(vector<int>& a, int n) {

	vector<int> b(n);


	int r = 2;

	for (int m = 0; m < r; m++) {
		int k = 131072;


		vector <int> c(k);

		for (int i = 0; i < k; i++) {
			c[i] = 0;
		}

		for (int i = 0; i < n; i++) {
			int d = digit(a[i], m);
			c[d]++;
		}
		int count = 0;
		for (int i = 0; i < k; i++) {
			int tmp = c[i];
			c[i] = count;
			count += tmp;
		}
		for (int i = 0; i < n; i++) {
			int d = digit(a[i], m);
			b[c[d]] = a[i];
			c[d]++;
		}
		for (int i = 0; i < n; i++) {
			a[i] = b[i];
		}
	}
}



int main()
{
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");

	int n, m;
	in >> n >> m;
	int k = n * m;
	vector < int> a(n + m);
	vector < int> c(k);

	int pos = 0;

	for (int i = 0; i < n + m; i++) {
		in >> a[i];
		if (i >= n) {
			for (int j = 0; j < n; j++) {
				c[pos] = a[j] * a[i];
				pos++;
			}
		}
	}

	int64_t sum = 0;


	radixSort(c, k);


	for (int i = 0; i < k; i += 10) {
		sum += c[i];
	}


	out << sum;


	out.close();
	in.close();
}