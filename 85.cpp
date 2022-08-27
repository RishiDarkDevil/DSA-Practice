// https://www.codechef.com/problems/MINEAT

#include <bits/stdc++.h>
using namespace std;

bool KComplete(vector<long long> &A, long long N, long long K, long long H) {
	long long time_taken = 0;
	for (long long i = 0; i < N; ++i) {
		if (K != 0)
			time_taken += ceil(((double)A[i])/((double)K));
		else
			time_taken += A[i];
	}
	return time_taken <= H;
}

int main() {
	long long t;
	cin >> t;
	while (t--) {
		long long N, H;
		cin >> N >> H;

		vector<long long> A;
		long long max_pile = LLONG_MIN;
		for (long long i = 0; i < N; ++i) {
			long long x;
			cin >> x;
			A.push_back(x);
			max_pile = max(max_pile, A[i]);
		}

		long long lo = 0, hi = max_pile, mid = 0;
		while (hi - lo  > 1) {
			mid = (hi + lo) / 2;
			if (KComplete(A, N, mid, H))
				hi = mid;
			else
				lo = mid + 1;
		}
		if (hi >= lo) {
			if (KComplete(A, N, lo, H))
				cout << lo << endl;
			else
				cout << hi << endl;
		} else {
			if (KComplete(A, N, hi, H))
				cout << hi << endl;
			else
				cout << lo << endl;
		}
	}
}