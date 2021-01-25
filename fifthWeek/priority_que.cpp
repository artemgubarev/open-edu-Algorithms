/*
Очередь с приоритетами на двух векторах. 
"Лучшим" т.е. приоритеным считается минимальный элемент.
fstream и ofsteam могут замедлить работу программы, 
чтобы избежать этого следует отправлять с расширением .c++
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

void priority_que();

struct element
{
	int value, step; // значение, строка добавления
};


struct priority_que_min
{
	int *indexes;
	vector <element> heap;

	void swap_s(int i, int j);
	void siftUp(int i);
	void siftDown(int i);
	void decreaseKey(int value, int step);
	int extractMin();
	void insert(int value, int step);
};


int main()
{	
	priority_que();

	return 0;
}


void priority_que()
{
	char command;
	int size, num, num_2, step = 1;
	priority_que_min que;

	in >> size;

	// выделяем память для значений индексов в векторе кучи
	que.indexes = new int[size]; 

	// ввод
	for (int i = 0; i < size; i++)
	{
		in >> command;

		switch (command)
		{

		case 'A':
			in >> num;
			que.insert(num, step);
			break;

		case 'D':
			in >> num >> num_2;
			que.decreaseKey(num_2, num);
			break;

		case 'X':
			if (que.heap.empty())
			{
				out << "*" << endl;
			}
			else  out << que.extractMin() << endl;
			break;
		}
		step++;
	}
}


void priority_que_min :: swap_s(int i, int j)
{
	swap(heap[i], heap[j]);
	// обновление значений индексов во втором векторе
	swap(indexes[heap[i].step], indexes[heap[j].step]);
}


void  priority_que_min::siftUp(int i)
{
	while (heap[i].value < heap[(i - 1) / 2].value)
	{
		swap_s(i, (i - 1) / 2);
		i = (i - 1) / 2;
	}
}


void  priority_que_min::siftDown(int i)
{
	while ((2 * i + 1) < heap.size())
	{
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		int j = left;

		if (right < heap.size() && heap[right].value < heap[left].value)
		{
			j = right;
		}

		if (heap[i].value <= heap[j].value)
		{
			break;
		}
		swap_s(i, j);
		i = j;
	}
}



void  priority_que_min::decreaseKey(int value, int step)
{
	int i = indexes[step];

	heap[i].value = value;
	siftUp(i);
}


int  priority_que_min::extractMin()
{
	int min = heap[0].value;

	swap_s(0, heap.size() - 1);
	heap.pop_back();
	siftDown(0);
	return min;
}


void  priority_que_min::insert(int value, int step)
{

	element add;
	add.value = value;
	add.step = step;

	heap.push_back(add);

	indexes[step] = heap.size() - 1;

	siftUp(heap.size() - 1);
}