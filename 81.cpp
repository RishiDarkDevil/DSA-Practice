#include <bits/stdc++.h>
using namespace std;

double sqrt_bin(double n, double eps = 1e-6) {
	double lo = 0, hi = n;
	double mid;
	while (hi-lo >= eps) {
		mid = (lo + hi) / 2;
		if (mid*mid < n)
			lo = mid;
		else
			hi = mid; 
	}
	return lo;
}

int main() {
	double n;
	cin >> n;
	cout << sqrt_bin(n);
}