// https://www.spoj.com/problems/ZSUM/

#include <bits/stdc++.h>
using namespace std;

long long bin_exp(long long a, long long b, long long mod=10000007) {
	a %= mod;
	long long ans = 1;
	while (b) {
		if (b & 1)
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans;
}

int main() {
	long long n, k;
	cin >> n >> k;
	long long mod = 10000007;
	while (n != 0 && k != 0) {
		cout << (bin_exp(n, k) + ((2 * bin_exp(n-1, k)) % mod) + bin_exp(n, n) + ((2 * bin_exp(n-1, n-1)) % mod)) % mod << endl;
		cin >> n >> k;
	}
}