#include <bits/stdc++.h>
using namespace std;

int A[1000000];

int main() {
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; ++i)
		cin >> A[i];

	unordered_set<int> second;

	for (int i = 0; i < n; ++i) {
		if (second.find(k-A[i]) != second.end()) {
			cout << "YES";
			return 0;
		}
		second.insert(A[i]);
	}
	cout << "NO";
}