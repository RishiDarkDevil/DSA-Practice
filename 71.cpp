// Very interesting question

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long m, n;
	cin >> n >> m;

	vector<long long> v;
	for (int i = 0; i < n; ++i) {
		long long num;
		cin >> num;
		v.push_back(num % m);
	}

	sort(v.begin(), v.end());

	int q;
	cin >> q;
	while (q--) {
		long long x;
		cin >> x;
		x %= m;
		auto ptr = upper_bound(v.begin(), v.end(), m-x-1);
		if (ptr != v.begin())
			ptr--;

		// we take the max as if all the elements are larger than m - x - 1, then adding x will bring us back
		// near the starting, thus adding the x to the maximum element will keep us ahead after revolving back to the start
		// Thus, we take the maximum of two
		cout << max((v[n - 1] + x) % m, (*ptr + x) % m)  << endl;
	}
}