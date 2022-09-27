// https://www.interviewbit.com/problems/subset-sum-problem/

#include <bits/stdc++.h>
using namespace std;

int dp[110][100010];

bool subset_sum(vector<int> &A, int B, int idx, int dp[][100010]) {
	if (B == 0) return true;
	if (idx >= A.size() || B < 0) return false;
	if (dp[idx][B] != -1) {
		if (dp[idx][B])
			return true;
		else
			return false;
	}
	bool way1 = subset_sum(A, B-A[idx], idx+1, dp);
	bool way2 = subset_sum(A, B, idx+1, dp);
	dp[idx][B] = (way1 || way2)? 1 : 0;
	return (way1 || way2);
}

int solve(vector<int> &A, int B) {
	memset(dp, -1, sizeof(dp));
	return (subset_sum(A, B, 0, dp)? 1 : 0);
}

int main() {
	int n;
	cin >> n;
	
	vector<int> A;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x; A.push_back(x);
	}

	int B;
	cin >> B;

	cout << (solve(A, B)? 1 : 0);
}