#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}

	vector<int> NGE(nums.size(), -1);
	stack<pair<int, int>> st;
	queue<int> que;

	for (int i = 0; i < nums.size(); ++i)
		que.push(nums[i]);

	// forward pass
	for (int i = 0; i < nums.size(); ++i) {
		while(!st.empty()) {
			if ((st.top()).first < nums[i]) {
				NGE[(st.top()).second] = i;
				st.pop();
			} else
				break;
		}
		st.push({nums[i], i});
	}

	// backward pass
	int k = 0;
	for (int i = nums.size()-1; i >= 0; i--) {
		if (NGE[i] == -1) {
			while(!que.empty()) {
				if (que.front() > nums[i]) {
					NGE[i] = k;
					break;
				} else
					que.pop();
					k++;
			}
		}
	}

	for (int i = 0; i < nums.size(); i++) {
		if (NGE[i] != -1)
			cout << nums[NGE[i]] << " ";
		else
			cout << -1 << " ";
	}
	cout << endl;
}