// https://www.codechef.com/problems/CHMOD

#include <bits/stdc++.h>
using namespace std;

int binExp(int a, int b, int m) {
	int ans = 1;
	while (b) {
		if (b & 1)
			ans = (ans * 1LL * a) % m;
		a = (a * 1LL * a) % m;
		b >>= 1;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;

	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	vector<int> lp(101, 0);

	for (int i = 2; i <= 100; ++i) {
		for (int j = 0; j < primes.size(); j++) {
			if (i % primes[j] == 0) {
				lp[i] = j;
				break;
			}
		}
	}
	
	int prime_count[n][primes.size()];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < primes.size(); ++j)
			prime_count[i][j] = 0;
	}

	for (int i = 0; i < n; ++i) {
		while (arr[i] > 1) {
			int prime_idx = lp[arr[i]];
			while (arr[i] % primes[prime_idx] == 0) {
				prime_count[i][prime_idx]++;
				arr[i] /= primes[prime_idx];
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < primes.size(); ++j) {
			if (i == 0)
				continue;
			prime_count[i][j] += prime_count[i-1][j];
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int l, r, m;
		cin >> l >> r >> m;
		int ans = 1;
		for (int i = 0; i < primes.size(); ++i) {
			int left = 0;
			if (l != 1)
				left = prime_count[l-2][i];
			int right = prime_count[r-1][i];
			if (right - left)
				ans = (ans * 1LL * binExp(primes[i], right - left, m)) % m;
		}
		cout << ans % m << endl;
	}
}