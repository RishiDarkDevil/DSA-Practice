// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

#include <bits/stdc++.h>
using namespace std;

int maximize(int price[], int n, int dp[]) {
	if (dp[n] != -1) return dp[n];
	if (n == 0) return 0;
	int profit = INT_MIN;
	for (int i = 1; i <= n; ++i) {
		if (n - i >= 0)
			profit = max(profit, maximize(price, n-i, dp) + price[i-1]);
	}
	return dp[n] = profit;
}

int cutRod(int price[], int n) {
	int dp[1010];
	memset(dp, -1, sizeof(dp));
	return maximize(price, n, dp);
}

int main() {
	int n;
	cin >> n;
	
	int price[n];
	for (int i = 0; i < n; ++i)
		cin >> price[i];

	cout << cutRod(price, n);
}