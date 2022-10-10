// https://leetcode.com/problems/longest-common-subsequence/

#include <bits/stdc++.h>
using namespace std;

int dp[1010][1010];

int lcs(string &text1, string &text2, int idx1, int idx2, int dp[][1010]) {
	if (idx1 < 0 || idx2 < 0) return 0;
	if (dp[idx1][idx2] != -1) return dp[idx1][idx2]; 
	if (text1[idx1] == text2[idx2])
		return dp[idx1][idx2] = 1 + lcs(text1, text2, idx1-1, idx2-1, dp);
	else 
		return dp[idx1][idx2] = max(lcs(text1, text2, idx1-1, idx2, dp), lcs(text1, text2, idx1, idx2-1, dp));
}

int longestCommonSubsequence(string text1, string text2) {
	memset(dp, -1, sizeof(dp));
	return lcs(text1, text2, text1.size()-1, text2.size()-1, dp);
}

int main() {
	string str1 ,str2;
	cin >> str1 >> str2;
	cout << longestCommonSubsequence(str1, str2);
}