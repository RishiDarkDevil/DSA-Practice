// https://atcoder.jp/contests/dp/tasks/dp_a

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int dp[N];

int min_cost(int start, vector<int> &heights) {
	if (dp[start] != -1) return dp[start];
	if (start == heights.size()-1) return 0;
	if (start == heights.size()-2) return abs(heights[heights.size()-1] - heights[heights.size()-2]);
	int path1 = abs(heights[start+1] - heights[start]) + min_cost(start+1, heights);
	int path2= abs(heights[start+2] - heights[start]) + min_cost(start+2, heights);
	return dp[start] = min(path1, path2);
}

int main() {
	int N;
	cin >> N;

	vector<int> heights;
	for (int i = 0; i < N; ++i) {
		int height;
		cin >> height;
		heights.push_back(height);
	}

	memset(dp, -1, sizeof(dp));

	cout << min_cost(0, heights);

}