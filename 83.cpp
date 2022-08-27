// https://www.spoj.com/problems/AGGRCOW/

#include <bits/stdc++.h>
using namespace std;

int N, C;
bool is_min_dist_suff(vector<long long> &stalls, long long dist) {
	int cows = C-1;
	auto it = stalls.begin();
	for (int i = 0; i < cows; ++i) {
		it = lower_bound(it, stalls.end(), dist + (*it));
		if (it == stalls.end()) return false;
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> N >> C;

		vector<long long> stalls;
		for (int i = 0; i < N; ++i) {
			long long x;
			cin >> x;
			stalls.push_back(x);
		}

		sort(stalls.begin(), stalls.end());

		long long lo = 0, hi = stalls[N-1]-stalls[0], mid = 0;
		while(hi - lo > 1) {
			mid = (lo + hi) / 2;
			if (is_min_dist_suff(stalls, mid))
				lo = mid;
			else
				hi = mid - 1;
		}
		if (hi >= lo) {
			if (is_min_dist_suff(stalls, hi))
				cout << hi << endl;
			else
				cout << lo << endl;
		} else {
			if (is_min_dist_suff(stalls, lo))
				cout << lo << endl;
			else
				cout << hi << endl;
		}
	}
}