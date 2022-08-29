// https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>
using namespace std;

vector<int> gen_subset(vector<int> &v, int num) {
	vector<int> subset;
	for (int i = v.size()-1; i >= 0; i--)
		if ((num >> i) & 1) subset.push_back(v[i]);
	return subset;
}

int main() {
	int n;
	cin >> n;
	
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	
	vector<vector<int>> subsets;	
	for (int i = 0; i < (1 << n); ++i)
		subsets.push_back(gen_subset(arr, i));

	for (auto &subset: subsets) {
		for (auto &num: subset) cout << num << " ";
		cout << endl;
	}
}