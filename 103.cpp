// https://codeforces.com/problemset/problem/230/B
// Once solved before naively here it takes half the time of the previous soln.

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
vector<bool> isPrime(N, true);

int main() {
	int n;
	cin >> n;

	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < N; ++i) {
		if (isPrime[i]) {
			for (int j = 2*i; j < N; j += i)
				isPrime[j] = false;
		}
	}

	long long x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		long long y = sqrt(x);
		if (y * y != x) {
			cout << "NO" << endl;
		} else {
			if (isPrime[y])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}	
}