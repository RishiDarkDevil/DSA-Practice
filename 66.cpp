#include <bits/stdc++.h>
using namespace std;

int generate(int n, int k) {
	if (n == 1 && k == 1)
		return 0;
	long long mid = pow(2, n-1) / 2;
	return (k <= mid)? generate(n-1, k):(!generate(n-1, k-mid));
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << generate(n, k);
}