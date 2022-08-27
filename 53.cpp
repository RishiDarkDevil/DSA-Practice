#include <bits/stdc++.h>
using namespace std;

int main() {
	int Q;
	cin >> Q;

	unordered_map<string, int> name_marks;
	for (int i = 0; i < Q; ++i) {
		int type, Y;
		string X;
		cin >> type;

		if (type == 1) {
			cin >> X >> Y;
			name_marks[X] = name_marks[X] + Y;
		}
		else if (type == 2) {
			cin >> X;
			name_marks[X] = 0;
		}
		else {
			cin >> X;
			cout << name_marks[X] << endl;
		}
	}
}