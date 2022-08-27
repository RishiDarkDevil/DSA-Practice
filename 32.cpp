#include <bits/stdc++.h>
using namespace std;

unsigned long long int prod_thru(int a, int b) {
	unsigned long long int prod = 1;
	for (int i = a; i <= b; ++i)
		prod *= i;
	if (b < a)
		prod = 0;
	return prod;
}

unsigned long long int bin_coef(int n, int k) {
	unsigned long long int num, den, coef;
	if (k <= n/2) {
		num = prod_thru(n-k+1, n);
		den = prod_thru(1, k);
	} else {
		num = prod_thru(k+1, n);
		den = prod_thru(1, n-k);
	}
	if (den == 0)
		coef = 1;
	else 
		coef = num/den;
	return coef;
}

void pascal(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			cout << bin_coef(i, j) << " ";
		}
		cout << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		pascal(n);
	}
}