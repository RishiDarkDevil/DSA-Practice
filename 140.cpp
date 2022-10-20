// https://leetcode.com/discuss/interview-question/889539/wells-fargo

#include <bits/stdc++.h>
using namespace std;

bool isProjEnough(vector<int> &scores, int p, int q, int x) {
	int num_projs = 0;
	for (auto &score: scores)
		num_projs += max(0, (int)ceil(score - q*x / ((p-q)*1.0)));
	return num_projs <= x;
}

int main() {
	// number of employees
	int n;
	cin >> n;

	// scores of the employees
	vector<int> scores; int max_score = 0;
	for (int i = 0; i < n; ++i) {
		int x; 
		cin >> x; 
		scores.push_back(x);
		max_score = max(max_score, x);
	}

	// P and Q
	int p, q;
	cin >> p >> q;

	// Binary Search the Solution between 0 and max_score 
	// cause the atleast as many projects will be needed so as to finish the max_score 
	int lb = 0, ub = max_score;
	while (lb < ub) {
		int mid = (lb+ub) / 2;
		if (isProjEnough(scores, p, q, mid))
			ub = mid;
		else
			lb = mid+1;
	}
	if (isProjEnough(scores, p, q, ub))
		cout << ub;
	else
		cout << lb;
}