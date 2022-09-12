// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 10;
int dp[M];

int min_cost(int start, int K, vector<int> &heights, int n) {
	if (dp[start] != -1) return dp[start];
	if (start == n - 1) return 0;
	int cost = INT_MAX;
	for (int i = 1; i <= K; ++i) {
		if (start + i < n)
			cost = min(cost, min_cost(start+i, K, heights, n) + abs(heights[start+i] - heights[start]));
		else
			break;
	}
	return dp[start] = cost;
}

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> heights;
	for (int i = 0; i < N; ++i) {
		int height;
		cin >> height;
		heights.push_back(height);
	}

	memset(dp, -1, sizeof(dp));

	cout << min_cost(0, K, heights, N);
}