#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");


struct data_tree
{
	int value, left, right;
};


struct node
{
	int value;
	node *left, *right;
};

vector <data_tree> data_t;
node *tree = NULL;
const int minInt = (1 << 30) * 2;
const int maxInt = minInt - 1;

void input();
void build(node *&tree, int index);
bool isSearchTree(node *p, int minKey, int maxKey);
bool isSearchTree_(node *root);

int main()
{
	input();

	if (data_t.size() == 0) out << "YES";
	else
	{
		build(tree, 0);
		isSearchTree_(tree) ? out << "YES" : out << "NO";
	}


	in.close();
	out.close();
}


bool isSearchTree(node *p, int minKey, int maxKey)
{
	if (p == nullptr)
		return true;
	if (minKey < p->value && p->value < maxKey)
		return isSearchTree(p->left, minKey, p->value) && isSearchTree(p->right, p->value, maxKey);
	return false;
}

bool isSearchTree_(node *root)
{
	return isSearchTree(root, minInt, maxInt);
}


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


void input()
{
	int size_tree;

	in >> size_tree;

	if (size_tree != 0)
	{

		for (int i = 0; i < size_tree; i++)
		{
			data_tree add;
			in >> add.value >> add.left >> add.right;

			data_t.push_back(add);
		}
	}
}
