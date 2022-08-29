// https://leetcode.com/problems/super-pow/

#include <bits/stdc++.h>
using namespace std;

long long bin_exp(int num, int power, int m) {
	num %= m;
	long long ans = 1;
	while (power) {
		if (power & 1)
			ans = ((ans % m) * (num % m)) % m;
		num = ((num % m) * (num % m)) % m;
		power >>= 1;
	}
	return ans;
}

long long bin_rep(vector<int> &b, int m) {
	long long ans = 0;
	for (int i = b.size()-1; i >= 0; i--)
		ans = ((ans % m ) + ((b[i] * bin_exp(10, b.size() - 1 - i, m)) % m)) % m; 
	return ans;
}

int superPow(int a, vector<int> &b) {
	a %= 1337;
	int expo = bin_rep(b, 1140);
	return bin_exp(a, expo, 1337);
}

int main() {
	int a;
	cin >> a;

	int n;
	cin >> n;
	vector<int> b;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		b.push_back(x);
	}

	cout << superPow(a, b);
}