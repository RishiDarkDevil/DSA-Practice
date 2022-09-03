// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/hacker-with-prime-bebe28ac/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
vector<int> isPrime(N, 1);
vector<int> lowestPrime(N, 0);
vector<int> hsh(N, 0);
vector<int> canRemove(N, 0);

vector<int> distinctPrime(int num) {
	vector<int> dp;
	while (num > 1) {
		int prime = lowestPrime[num];
		while (num % prime == 0) num /= prime;
		dp.push_back(prime);
	}
	return dp;
}

int main() {
	int n, q;
	cin >> n >> q;
	
	isPrime[0] = isPrime[1] = 0;
	lowestPrime[0] = lowestPrime[1] = -1;
	for (int i = 2; i < N; ++i) {
		if (isPrime[i]) {
			for (int j = i; j < N; j += i) {
				isPrime[j] = 1;
				if (lowestPrime[j] == 0)
					lowestPrime[j] = i;
			}
		}
	}
	canRemove[1] = 1;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		hsh[x] = 1;
		canRemove[x] = 1;
	}

	for (int i = 2; i < N; ++i) {
		if (hsh[i]) {
			for (long long j = i; j < N; j *= i)
				canRemove[j] = 1;
		}
	}
	while (q--) {
		int x;
		cin >> x;

		vector<int> distPrimes = distinctPrime(x);
		bool isPossible = false;
		for (int i = 0; i < distPrimes.size(); ++i) {
			for (int j = i; j < distPrimes.size(); ++j) {
				int prod = distPrimes[i] * distPrimes[j];
				if (i == j && x % prod != 0) continue;
				int toRemove = x / prod;
				if (canRemove[toRemove]) {
					isPossible = true;
					break;
				}
			}
			if (isPossible) break;
		}
		cout << ((isPossible)? "YES" : "NO") << endl;
	}
}