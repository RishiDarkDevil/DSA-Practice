#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, Q;
		cin >> N >> Q;

		int A[N+1], forward[N+1], backward[N+2];
		for (int i = 1; i <= N; ++i)
			cin >> A[i];

		forward[0] = backward[N+1] = 0;
		for (int i = 1; i <= N; ++i)
			forward[i] = __gcd(forward[i-1], A[i]);

		for (int i = N; i >= 1; --i)
			backward[i] = __gcd(A[i], backward[i+1]);

		while (Q--) {
			int L, R;
			cin >> L >> R;
			cout << __gcd(forward[L-1], backward[R+1]) << endl;
		}
	}

}