#include <bits/stdc++.h>
using namespace std;

long long bin_mult(long long a, long long b) {
	long long ans = 0;
	while (b) {
		if (b & 1)
			ans += a;
		a += a;
		b >>= 1;
	}
	return ans;
}

int main() {
	long long a, b;
	cin >> a >> b;
	cout << bin_mult(a, b);
}