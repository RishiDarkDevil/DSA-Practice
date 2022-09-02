#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> prime_factors;
	for (int i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			prime_factors.push_back(i);
			n /= i;  
		}
	}
	if (n > 1)
		prime_factors.push_back(n);
	for (int i = 0; i < prime_factors.size(); ++i)
		cout << prime_factors[i] << " ";
}