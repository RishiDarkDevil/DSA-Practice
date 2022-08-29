#include <bits/stdc++.h>
using namespace std;

long long bin_exp(long long a, long long b) {
	if (b == 0) return 1;
	long long res = bin_exp(a, b/2);
	return (b&1)? (a * res * res) : (res * res);
}

int main() {
	long long a, b;
	cin >> a >> b;
	cout << bin_exp(a, b);
}