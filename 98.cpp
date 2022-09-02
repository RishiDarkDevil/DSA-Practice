#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
vector<bool> isPrime(N, 1);
vector<int> lowestPrime(N, 0), highestPrime(N, 0);

int main() {
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < N; ++i) {
		if (isPrime[i]) {
			lowestPrime[i] = highestPrime[i] = i;
			for (int j = 2 * i; j < N; j += i) {
				isPrime[j] = false;
				highestPrime[j] = i;
				if (!lowestPrime[j])
					lowestPrime[j] = i;
			}
		}
	}
	
	int num;
	cin >> num;
	vector<int> prime_factors;
	while (num > 1) {
		int prime_factor = lowestPrime[num];
		while (num % prime_factor == 0) {
			prime_factors.push_back(prime_factor);
			num /= prime_factor;
		}
	}

	for (auto &prime_factor: prime_factors)
		cout << prime_factor << " "; 
}