#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> piles(n+1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> piles[i];
		piles[i] += piles[i-1];
	}

	sort(piles.begin(), piles.end());

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		auto it = lower_bound(piles.begin(), piles.end(), x);
		cout << distance(piles.begin(), it) << endl;
	}
}