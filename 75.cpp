#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
	return ((a.first + a.second) == (b.first + b.second))? (a < b):((a.first + a.second) < (b.first + b.second));
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<pair<long long, long long>> v;
		for (int i = 0; i < n; ++i) {
			long long x, y;
			cin >> x >> y;
			v.push_back({x, y});
		}
		vector<pair<long long, long long>> w = v;

		sort(v.begin(), v.end(), cmp);

		map<pair<long long, long long>, int> rank;
		int k = 0;
		for (auto &i: v) {
			rank[i] = k;
			k++;
		}
		for (auto &i: w)
			cout << rank[i] << " ";
		cout << endl;
	}
}