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
	for (int i = 0; i < 100; ++i)
		cout << i << " " << highestPrime[i] << " " << lowestPrime[i] << endl;
}