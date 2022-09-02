#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int main() {
	vector<int> divisors[N];
	divisors[1].push_back(1);
	for (int i = 2; i < N; ++i) {
		for (int j = i; j < N; j += i) {
			divisors[j].push_back(i);
		}
	}

	for (int i = 1; i < N; ++i) {
		cout << i << ": ";
		for (auto &div: divisors[i])
			cout << div << " ";
		cout << endl;
	}
}