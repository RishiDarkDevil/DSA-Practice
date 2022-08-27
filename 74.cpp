#include <bits/stdc++.h>
using namespace std;

int num_stop_islands(vector<pair<int, int>> D_A, int K, int F) {
	multiset<int> visited_food;
	int curr = 0, ans = 0;
	for (int i = 1; i < K; ++i) {
		F--;
		if (i == D_A[curr].first)
			visited_food.insert(D_A[curr++].second);
		if (F <= 0) {
			if (visited_food.size() == 0)
				return -1;
			else {
				auto it = --visited_food.end();
				F += *it;
				visited_food.erase(it);
				ans++;
			}
		}
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int N, K, F;
		cin >> N >> K >> F;

		vector<pair<int, int>> D_A;
		for (int i = 0; i < N; ++i) {
			int d, a;
			cin >> d >> a;
			D_A.push_back({K-d, a});
		}

		sort(D_A.begin(), D_A.end());

		cout << num_stop_islands(D_A, K, F) << endl;
	}
}