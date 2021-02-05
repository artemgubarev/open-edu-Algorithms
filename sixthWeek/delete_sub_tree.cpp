
ifstream in("input.txt");
ofstream out("output.txt");


struct data_tree
{
	int value, left, right;
	bool is_delete;
};


vector <data_tree> tree;
int nodes = 0, nodes_sub_tree = 0;

void input();
void size_sub_tree(int index);
void remove(int index, int key);
void delete_sub_tree();

int main()
{
	input();

	nodes = tree.size();

	delete_sub_tree();

	in.close();
	out.close();
}


void size_sub_tree(int index)
{
	if (tree[index].left != 0 && !tree[tree[index].left - 1].is_delete)
		size_sub_tree(tree[index].left - 1);
	if (tree[index].right != 0 && !tree[tree[index].right - 1].is_delete)
		size_sub_tree(tree[index].right - 1);
	nodes_sub_tree++;
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
			add.is_delete = false;

			tree.push_back(add);
		}
	}
}


void remove(int index, int key)
{

	if (tree[index].is_delete == true)return;

	if (tree[index].value == key)
	{
		tree[index].is_delete = true;
		size_sub_tree(index);
		return;
	}

	if (tree[index].value > key) {
		if (tree[index].left != 0)remove(tree[index].left - 1, key);
		return;
	}

	if (tree[index].right != 0)remove(tree[index].right - 1, key);

}



void delete_sub_tree()
{
	int size_key, key;
	in >> size_key;

	for (int i = 0; i < size_key; i++)
	{
		nodes_sub_tree = 0;

		in >> key;

		remove(0, key);

		nodes -= nodes_sub_tree;

		out << nodes << endl;
	}
}