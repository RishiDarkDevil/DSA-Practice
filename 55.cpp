#include <bits/stdc++.h>
using namespace std;

int main() {
	int Q;
	cin >> Q;

	unordered_set<int> elements;
	for (int i = 0; i < Q; ++i) {
		int y, x;
		cin >> y >> x;

		if (y == 1) {
			elements.insert(x);
		}
		else if (y == 2) {
			if (elements.find(x) != elements.end())
				elements.erase(x);
		}
		else {
			if (elements.find(x) != elements.end())
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
}