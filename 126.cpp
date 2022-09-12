// https://leetcode.com/problems/longest-increasing-subsequence/

#include <bits/stdc++.h>
using namespace std;

// returns LIS length for subsequence rooted at index start
int LIS(int start, vector<int> &nums, int dp[]) {
	if (dp[start] != 0) return dp[start];
	if (start >= nums.size()) return 0;
	int length = 1;
	for (int i = start+1; i < nums.size(); ++i) {
		if (nums[i] > nums[start])
			length = max(length, LIS(i, nums, dp)+1);
	}	
	return dp[start] = length;
}

int lengthOfLIS(vector<int> &nums) {
	int dp[2510] = {0};
	int length = INT_MIN;
	// max of all rooted subsequence
	for (int i = 0; i < nums.size(); ++i) {
		length = max(length, LIS(i, nums, dp));
	}
	return length;
}

int main() {
	int n;
	cin >> n;

	vector<int> sequence;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		sequence.push_back(x);
	}

	cout << lengthOfLIS(sequence);
}