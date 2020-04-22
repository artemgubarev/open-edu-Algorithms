#include <iostream>
#include <fstream>

using namespace std;



int main()
{
	ifstream fin;
	fin.open("input.txt");
	ofstream fout;
	fout.open("output.txt");

	int n;
	fin >> n;

	int a[n];
	for (int i = 0; i < n; i++) {
		fin >> a[i];
	}

	int min = 0;
	int k = 0;

	for (int i = 0; i < n; i++) {
		min = a[i];
		for (int j = i; j < n; j++) {
			if (a[j] <= min) {
				min = a[j];
				k = j;
			}
		}
		if (a[i] != min) {
			int temp = a[i];
			a[i] = min;
			a[k] = temp;
			fout << "Swap elements at indices " << i + 1 << " and " << k + 1 << "." << endl;
		}
	}


	fout << "No more swaps needed." << endl;


	for (int i = 0; i < n; i++) {
		fout << a[i] << " ";
	}

	fin.close();
	fout.close();
}