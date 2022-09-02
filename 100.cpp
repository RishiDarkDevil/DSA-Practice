// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/name-count/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int M = 1e9 + 7;
int factorial[N];

int binExp(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1)
			ans = (ans * 1LL * a) % M;
		a = (a * 1LL * a) % M; 
		b >>= 1;
	}
	return ans;
}

int main() {
	factorial[0] = 1;
	for (int i = 1; i < N; ++i)
		factorial[i] = (factorial[i-1] * 1LL * i) % M;
	
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int num = factorial[k];
		int deno = factorial[k-n];
		int perm = (num * 1LL * binExp(deno, M-2)) % M;
		cout << perm << endl;
	}
}