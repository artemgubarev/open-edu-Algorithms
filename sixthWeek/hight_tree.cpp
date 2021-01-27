#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");


// входные данные о дереве
struct data_tree
{
	int value, left, right;
};

// узлы дерева
struct node
{
	int value;
	node *left, *right;
};


vector <data_tree> data_t;
node *tree = NULL;


void input();
int height(node *&tree);
void build(node *&tree, int index);


int main()
{
	input();

	if (data_t.size() != 0)
	{
		build(tree, 0);
		out << height(tree);
	}

	else out << 0;

	in.close();
	out.close();
}



void input()
{
	int size;

	in >> size;

	if (size != 0)
	{

		for (int i = 0; i < size; i++)
		{
			data_tree j;
			in >> j.value >> j.left >> j.right;

			data_t.push_back(j);
		}
	}
}


// рекурсивное построение дерева на основе входных данных
void build(node *&tree, int index)
{
	tree = new node;
	tree->value = data_t[index].value;
	tree->left = tree->right = NULL;

	if (data_t[index].left != 0)
	{
		build(tree->left, data_t[index].left - 1);
	}

	if (data_t[index].right != 0)
	{
		build(tree->right, data_t[index].right - 1);
	}
}

// обход дерева с вычилением его высоты
int height(node *&tree)
{
	int l, r, h = 0;
	if (tree != NULL) {
		l = height(tree->left);
		r = height(tree->right);
		h = ((l > r) ? l : r) + 1;
	}
	return h;
}