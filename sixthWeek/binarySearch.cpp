#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");


bool is_search(int *arr, int left, int right, int key)
{
	int midd = 0;
	while (1)
	{
		midd = (left + right) / 2;

		if (key < arr[midd])
			right = midd - 1;
		else if (key > arr[midd])
			left = midd + 1;
		else
			return true;

		if (left > right)
			return false;
	}
}


int binarySearch(int *a, int fromIndex, int toIndex, int key, bool last) {
	int low = fromIndex;
	int high = toIndex - 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		int midVal = a[mid];

		if (midVal < key || (last && midVal == key))
			low = mid + 1;
		else if (midVal > key || (!last && midVal == key))
			high = mid - 1;
	}
	return last ? high : low;
}

int main()
{
	int n, m;

	in >> n;

	int *dig = new int[n];
	for (int i = 0; i != n; i++) in >> dig[i];

	in >> m;
	int *inq = new int[m];

	int first, last;

	for (int i = 0; i != m; i++) {
		in >> inq[i];
		if (!is_search(dig, 0, n, inq[i])) {
			first = -1;
			last = -1;
		}
		else {
			last = binarySearch(dig, 0, n, inq[i], true);
			first = binarySearch(dig, 0, n, inq[i], false);
			last++;
			first++;
		}

		out << first << " " << last << endl;
	}


	in.close();
	out.close();
	return 0;
}
