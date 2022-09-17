// https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>
using namespace std;

int w[110], v[110];
long long dp[110][100010];

long long maximize(int ind, int W, int N) {
	if (dp[ind][W] != -1) return dp[ind][W];
	if (W == 0 || ind == N) return 0;
	long long ans, way1 = 0, way2 = 0;
	// Don't treat it like the grid problems i.e. call the function and later check if it is valid input or not
	// As in that case like in DFS you simply can return, but in this case you are adding the value to the bag
	// Later discovering that the item didn't fit you should remove the added weight too
	// So, rather than taking that long route simply don't put it if it doesn't fit
	if (W >= w[ind]) way1 = maximize(ind+1, W-w[ind], N) + v[ind]*1LL;
	way2 = maximize(ind+1, W, N);
	ans = max(way1, way2);
	return dp[ind][W] = ans;
}

int main() {
	for (int i = 0; i < 110; ++i) {
		for (int j = 0; j < 100010; ++j)
			dp[i][j] = -1;
	}

	int N, W;
	cin >> N >> W;

	for (int i = 0; i < N; ++i)
		cin >> w[i] >> v[i];

	cout << maximize(0, W, N);
}