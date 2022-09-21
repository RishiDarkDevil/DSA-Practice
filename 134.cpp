// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

#include <bits/stdc++.h>
using namespace std;

int min_mult(vector<int> &dims, int i, int j, int dp[][110]) {
	if (dp[i][j] != -1) return dp[i][j];
	if (i == j) return 0;
	int num_mults = INT_MAX;
	for (int k = i; k < j; k++)
		num_mults = min(num_mults,  min_mult(dims, i, k, dp) + min_mult(dims, k+1, j, dp) + (dims[i-1] * dims[k] * dims[j]));
	return dp[i][j] = num_mults;
}

int matrixMultiplication(int N, int arr[]) {
	int dp[110][110];
	memset(dp, -1, sizeof(dp));
	vector<int> dims(arr, arr+N);
	return min_mult(dims, 1, N-1, dp);    
}

int main() {
	// Number of matrices
	int n;
	cin >> n;

	// Dimensions of the matrices
	int dims[n+1];
	for (int i = 0; i < n+1; ++i)
		cin >> dims[i];

	cout << matrixMultiplication(n+1, dims);

}