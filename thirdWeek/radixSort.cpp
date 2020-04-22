#include <cmath>
#include <string>
#include <iostream>
#include <fstream>



using namespace std;


void countSort(string str, int *arrIndex, int n) {

	int *resultIndex = new int[n]; // ��������� ������

	const int len = 26;
	int *c = new int[len];
	for (int i = 0; i < len; i++) { // ������ ������� �������� ��������� ������
		c[i] = 0;
	}

	for (int i = 0; i < n; i++) { // ������ ������� ��� ����������� �����
		c[str[i] - 97]++;
	}


	for (int i = 1; i < len; i++) { // ����� ���������� ���� �� ��������� ������ �����
		c[i] += c[i - 1];
	}


	for (int i = n - 1; i >= 0; i--) {
		int index = str[arrIndex[i] - 1] - 97; // ����� �������� ����� � ����� �������
		int count = c[index] - 1;				// ����� ���������� �� ����������� ��� ����.
		resultIndex[count] = arrIndex[i];		// ���������� � ��������� ������ �������� �� ������ count ������� ������
		c[index]--;								// �������� ���������� �� ����������� ���������
	}

	for (int i = 0; i < n; i++) {
		arrIndex[i] = resultIndex[i];
	}


	delete[] resultIndex;
}


int main()
{
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");

	int n, m, k;
	in >> n >> m >> k;

	int *index = new int[n];
	string *str = new string[m]; // �������� ������


	for (int i = 0; i < m; i++) { // �������������� ������
		in >> str[i];
	}

	for (int i = 0; i < n; i++) { //  �������������� �������
		index[i] = i + 1;
	}


	for (int i = m - 1; i >= 0 && k > 0; i--, k--) { // �������� ���������� �������� ���� ������ ��� ���� �� �����������
		countSort(str[i], index, n);
	}

	for (int i = 0; i < n; i++) { // ������� ��������� �������� ��������
		out << index[i] << " ";
	}

	delete[] index;
	delete[] str;

	out.close();
	in.close();
}