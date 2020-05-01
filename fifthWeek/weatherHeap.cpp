#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
#include <utility>
#include <iterator>
#include <cstdio>
#include <cstdlib>


using namespace std;


int main() {

	ifstream in("input.txt");
	ofstream out("output.txt");

	int n;

	in >> n;

	int *arr = new int[n + 1];


	for (int i = 1; i < n + 1; i++) {
		in >> arr[i];
	}

	int i;

	for (i = 1; i <= n / 2; i++) {
		if (2 * i <= n && arr[i] > arr[2 * i]) break;
		if (2 * i + 1 <= n && arr[i] > arr[2 * i + 1]) break;
	}

	if (i <= n / 2) out << "NO";
	else out << "YES";

	delete[] arr;

	out.close();
	in.close();



}