#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	int d, k1 = 0, k2 = 0;
	for (int i = 0; i < S.size(); ++i) {
		d = int(S[i]) - 48;
		if (((d == 1) && (i % 2 == 0)) || ((d == 0) && (i % 2 == 1)))
			k1++;
		if (((d == 0) && (i % 2 == 0)) || ((d == 1) && (i % 2 == 1)))
			k2++;
	}
	cout << min(k1, k2);
}