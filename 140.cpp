#include <bits/stdc++.h>
using namespace std;

int findProjects(priority_queue<int> &scores, int p, int q) {
	int val_spent = 0, ans = 0;
	int top = scores.top();
	while (top >= val_spent) {
		top = top - p + q;
		scores.pop();
		scores.push(top);
		top = scores.top();
		val_spent += q;
		ans++;
	}
	return ans;

}

int main() {
	int n;
	cin >> n;

	priority_queue<int> scores;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x; scores.push(x);
	}

	int p, q;
	cin >> p >> q;

	cout << findProjects(scores, p, q);

}