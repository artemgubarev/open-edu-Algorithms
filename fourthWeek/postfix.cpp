#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
#include <utility>
#include <iterator>
#include <cstdio>
#include <cstdlib>


using namespace std;


int main() {

	ifstream in("input.txt");
	ofstream out("output.txt");

	int n;

	in >> n;


	stack <int> st;

	char ch;
	int i;
	int temp;

	while (in >> ch) {
		if (isdigit(ch)) {
			in.putback(ch);
			in >> i;
			st.push(i);
		}
		else {
			switch (ch) {
			case '+': temp = st.top(); st.pop(); st.top() += temp; break;
			case '-': temp = st.top(); st.pop(); st.top() -= temp; break;
			case '*': temp = st.top(); st.pop(); st.top() *= temp; break;
			}
		}
	}

	out << st.top();



	out.close();
	in.close();



}