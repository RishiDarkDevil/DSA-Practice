// https://leetcode.com/problems/count-primes/

#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
	int num_primes = 0;
	vector<bool> isPrime(n+1, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < n; ++i) {
		if (isPrime[i]) {
			num_primes++;
			for (int j = 2 * i; j < n; j += i)
				isPrime[j] = false;
		}
	}
	return num_primes;
}

int main() {
	int n;
	cin >> n;
	cout << countPrimes(n);
}