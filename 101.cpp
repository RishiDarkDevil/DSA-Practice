// https://www.hackerearth.com/problem/algorithm/monk-and-divisor-conundrum-56e0eb99/
// Sieve Algo has O(nlogn) complexity here as n/2 + n/3 + .... = n.log(n)

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int divisors[N];
int hsh[N];

int main() {
	int n;
	cin >> n;
	
	int A[n];
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
		hsh[A[i]]++;
	}

	divisors[1] = n;
	for (int i = 2; i < N; ++i) {
		for (int j = i; j < N; j += i)
			divisors[i] += hsh[j];
	}

	int t;
	cin >> t;
	while (t--) {
		int p, q;
		cin >> p >> q;
		long long lcm = (p*1LL*q)/__gcd(p, q);
		cout << divisors[p] + divisors[q] - ((lcm < N)? divisors[lcm]:0) << endl;
	}
}