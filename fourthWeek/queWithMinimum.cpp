#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
#include <utility>

using namespace std;


class queue {

private:
	deque <int> q, min;

public:
	void put(int x) {
		q.push_back(x);
		while (!min.empty() && x < min.back()) min.pop_back();
		min.push_back(x);
	}

	int get_min() {
		return min.front();
	}

	void pop() {
		if (!q.empty()) {
			if (min.front() == q.front()) min.pop_front();
			q.pop_front();
		}
	}
};



int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");



	int n;
	in >> n;

	queue temp;
	char ch;

	int *que = new int[n];
	int j = 0;

	while (in.get(ch)) {
		if (ch == '+') {
			in >> que[j];
			temp.put(que[j]);
			j++;
		}

		if (ch == '-') {
			temp.pop();
		}

		if (ch == '?') {
			out << temp.get_min() << endl;
		}
	}


	delete[] que;


	out.close();
	in.close();
}