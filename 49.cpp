#include <bits/stdc++.h>
using namespace std;

map<int, long long int> dp;

long long int fibb(int n) {
	if (n == 1 || n == 2) return 1;
	if (dp[n]) return dp[n]; 
	dp[n-1] = fibb(n-1)%1000000007;
	dp[n-2] = fibb(n-2)%1000000007;
	dp[n] = (dp[n-1] + dp[n-2]) % 1000000007;
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	cout << fibb(n);
}