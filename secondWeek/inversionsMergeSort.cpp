#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int64_t count = 0;

void merge(int *A, int first, int last)
{
	int middle, start, final, j;
	int *mas = new int[100000];
	middle = (first + last) / 2;
	start = first; 
	final = middle + 1; 

	while (start <= middle && final <= last) {
		if (A[start] > A[final]) {
			count += middle - start + 1;
			final++;
		}
		else {
			start++;
		}
	}

	middle = (first + last) / 2;
	start = first;
	final = middle + 1;

	for (j = first; j <= last; j++)
		if ((start <= middle) && ((final > last) || (A[start] < A[final])))
		{
			mas[j] = A[start];
			start++;
		}
		else
		{
			mas[j] = A[final];
			final++;
		}
	for (j = first; j <= last; j++) A[j] = mas[j];
	delete[]mas;
};

void mergeSort(int *A, int first, int last)
{
	{
		if (first < last)
		{
			mergeSort(A, first, (first + last) / 2);
			mergeSort(A, (first + last) / 2 + 1, last);
			merge(A, first, last); 
		}
	}
};

int main()
{

	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");

	int n;
	in >> n;

	int *a  = new int[n];

	for (int i = 0; i < n; i++) {
		in >> a[i];
	}


	mergeSort(a, 0, n - 1);

	out << count;


	in.close();
	out.close();

}