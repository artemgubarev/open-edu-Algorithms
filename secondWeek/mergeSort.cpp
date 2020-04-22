#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <algorithm>


using namespace std;

std::ifstream in("input.txt");

std::ofstream out("output.txt");



void merge(int *a, int left, int right) {
	int *c = new int[100000];

	int mid = (left + right) / 2;
	int start = left;
	int final = mid + 1;
	int i;


	for (i = left; i <= right; i++) {
		if ((start <= mid) && ((final > right) || (a[start] < a[final]))) {
			c[i] = a[start];
			start++;
		}
		else {
			c[i] = a[final];
			final++;
		}
	}

	for (i = left; i <= right; i++) {
		a[i] = c[i];
	}
	delete[]c;
}
void mergeSort(int *a, int left, int right) {

	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, right);
		out << left + 1 << " " << right + 1 << " " << a[left] << " " << a[right] << endl;
	}
}




int main() {


	int n;
	in >> n;

	int *a = new int[n];

	for (int i = 0; i < n; i++) {
		in >> a[i];
	}


	mergeSort(a, 0, n - 1);


	for (int i = 0; i < n; i++) {
		out << a[i] << " ";
	}


	in.close();
	out.close();
}