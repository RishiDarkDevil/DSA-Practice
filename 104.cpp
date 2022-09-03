// https://codeforces.com/contest/776/problem/B

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<bool> isPrime(n + 10, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 0; i < n + 10; ++i) {
		if (isPrime[i]) {
			for (int j = 2 * i; j < n + 10; j += i)
				isPrime[j] = false;
		}
	}
	
	cout << ((n > 2)? 2 : 1) << endl;
	for (int i = 2; i <= n+1; ++i)
		cout << ((isPrime[i])? 1 : 2) << " ";
}