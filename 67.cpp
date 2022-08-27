#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets;
 
void gen(vector<int> &v, vector<int> &nums, int left) {
	if (left == 0) {
		subsets.push_back(v);
		return;
	}
	v.push_back(nums[nums.size()-left]);
	gen(v, nums, left-1);
	v.pop_back();
	gen(v, nums, left-1);
}

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
		cin >> nums[i];
	vector<int> subset;
	gen(subset, nums, nums.size());
	for (auto &i: subsets) {
		for (auto &j: i)
			cout << j << " ";
		cout << endl; 
	}
}