#include <cmath>
#include <string>
#include <iostream>
#include <fstream>



using namespace std;


void countSort(string str, int *arrIndex, int n) {

	int *resultIndex = new int[n]; // резервный массив

	const int len = 26;
	int *c = new int[len];
	for (int i = 0; i < len; i++) { // массив подчета значений заполняем нулями
		c[i] = 0;
	}

	for (int i = 0; i < n; i++) { // подчет сколько раз встречается буква
		c[str[i] - 97]++;
	}


	for (int i = 1; i < len; i++) { // какое количество букв не привышает данную букву
		c[i] += c[i - 1];
	}


	for (int i = n - 1; i >= 0; i--) {
		int index = str[arrIndex[i] - 1] - 97; // берем значение буквы с конца массива
		int count = c[index] - 1;				// берем количество не привышающих его знач.
		resultIndex[count] = arrIndex[i];		// записываем в резервный массив индексов на индекс count текущий индекс
		c[index]--;								// понижаем количество не привыщающих элементов
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
	string *str = new string[m]; // выделяем память


	for (int i = 0; i < m; i++) { // инициализируем строки
		in >> str[i];
	}

	for (int i = 0; i < n; i++) { //  инициализируем индексы
		index[i] = i + 1;
	}


	for (int i = m - 1; i >= 0 && k > 0; i--, k--) { // вызываем сортировку подчетом пока строки или фазы не закончаться
		countSort(str[i], index, n);
	}

	for (int i = 0; i < n; i++) { // выводим измененые значения индексов
		out << index[i] << " ";
	}

	delete[] index;
	delete[] str;

	out.close();
	in.close();
}