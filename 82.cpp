// https://www.spoj.com/problems/EKO/

#include <bits/stdc++.h>
using namespace std;

long long N, M;
long long trees[1000000];

bool is_wood_enough(long long H) {
	long long total_wood = 0;
	for (int i = 0; i < N; ++i)
		total_wood += max(trees[i] - H, 0*1LL);
	return total_wood >= M;
}

int main() {
	cin >> N >> M;

	long long min_H = INT_MAX, max_H = INT_MIN;
	for (long long i = 0; i < N; ++i) {
		cin >> trees[i];
		min_H = min(min_H, trees[i]);
		max_H = max(max_H, trees[i]);
	}

	long long lo = min_H, hi = max_H, mid = 0;
	while(hi - lo > 1) {
		mid = (lo + hi) / 2;
		if (is_wood_enough(mid))
			lo = mid;
		else
			hi = mid-1;
	}
	bool hi_H = is_wood_enough(hi);
	if (hi_H)
		cout << hi;
	else
		cout << lo;
}