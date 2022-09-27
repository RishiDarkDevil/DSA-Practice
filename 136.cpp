// https://leetcode.com/problems/partition-equal-subset-sum/

#include <bits/stdc++.h>
using namespace std;

int dp[210][200*100 + 10];

bool subset_sum(vector<int> &A, int B, int idx, int dp[][200*100 + 10]) {
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

bool canPartition(vector<int>& nums) {
	memset(dp, -1, sizeof(dp));
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (2*(sum/2) != sum) return false;
	return subset_sum(nums, sum/2, 0, dp);
}

int main() {
	int n;
	cin >> n;
	
	vector<int> A;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x; A.push_back(x);
	}

	cout << (canPartition(A)? 1 : 0);
}