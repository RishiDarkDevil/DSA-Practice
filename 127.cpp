// https://leetcode.com/problems/coin-change/

#include <bits/stdc++.h>
using namespace std;

int min_coins(int amt, vector<int> &coins, int dp[]) {
	if (amt == 0) return 0;
	if (amt < 0) return -1;
	if (dp[amt] != -2) return dp[amt];
	int coins_used = INT_MAX; bool isPossible = false;
	for (auto coin: coins) {
		int used_coin_ispossible = min_coins(amt-coin, coins, dp);
		if (used_coin_ispossible != -1) {
			coins_used = min(coins_used, used_coin_ispossible + 1);
			isPossible = true;
		}
	}
	if (isPossible)
		return dp[amt] = coins_used;
	else
		return dp[amt] = -1;
}

int coinChange(vector<int> &coins, int amount) {
	int dp[amount+10];
	for (int i = 0; i < amount+10; ++i)
		dp[i] = -2;
	int ans = min_coins(amount, coins, dp);
	return ans;
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
	cout << coinChange(coins, amt);
}