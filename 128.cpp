// https://leetcode.com/problems/coin-change-ii/

#include <bits/stdc++.h>
using namespace std;

int change_dp(int ind, int amount, vector<int> &coins, int dp[][5010]) {
	if (amount == 0) return 1;
	if (ind < 0) return 0;
	if (dp[ind][amount] != -1) return dp[ind][amount];

	int ans = 0;
	// Basically all branches of first coin first and then second and so on in the coins vector
	for (int coin_amount = 0; coin_amount <= amount; coin_amount += coins[ind]) {
		if (amount >= coin_amount)
			ans += change_dp(ind - 1, amount - coin_amount, coins, dp);
	}

	return dp[ind][amount] = ans;
}

int change(int amount, vector<int> &coins) {
	int dp[310][5010];
	for (int i = 0; i < 310; ++i) {
		for (int j = 0; j < 5010; ++j)
			dp[i][j] = -1;
	}

	return change_dp(coins.size()-1, amount, coins, dp);
}

int main() {
	int n, amt;
	cin >> n >> amt;
	vector<int> coins;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		coins.push_back(x);
	}
	cout << change(amt, coins);
}