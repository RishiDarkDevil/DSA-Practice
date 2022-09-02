// https://www.spoj.com/problems/MAS/ 

// Learnt Important Concept of double sum:
// sum_i=1 to n sum_j=i+1 to n A[i]A[j] = sum_i=1 to n A[i](total_sum - A[i]), where total_sum = sum of all A[i]
// This is because, you fix one i and now j sums over i+1 to n, now there are times before the outer loop was fixed 
// that is 1 to i-1, when inner loop had i in that case i sums from 1 to i-1, thus only the ith term is not added
// Idea of proof:
// 2 sum sum Ai.Aj = sum sum Ai.Aj + sum sum Ai.Aj Now, flip the second sum sum and then pull out i = 1 from 1st sum and see 

#include <bits/stdc++.h>
using namespace std;

const long long mod = 2760727302517;

long long binMult(long long a, long long b) {
	a %= mod;
	long long ans = 0;
	while (b) {
		if (b & 1) 
			ans = (ans + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return ans;
}

void update_F(long long &F_A, long long A[], int n, long long &sum, long long x, long long v) {
	long long new_sum = (sum + v - A[x] + mod) % mod;
	F_A = (F_A + binMult(n, (binMult(v, v) - binMult(A[x], A[x]) + mod) % mod) + (binMult(sum, sum) - binMult(new_sum, new_sum) + mod) % mod) % mod;
	sum = new_sum;
}

int main() {
	int t;
	cin >> t;
	for (int r = 1; r <= t; r++) {
		int flag = 1;
		long long n, Q;
		cin >> n >> Q;

		long long A[n+1] = {0};
		for (int i = 1; i <= n; ++i)
			cin >> A[i];

		long long sum = 0;
		for (int i = 1; i <= n; ++i)
			sum = (sum + A[i]) % mod;

		long long F_A = 0;
		for (int i = 1; i <= n; ++i)
			F_A = (F_A + binMult(binMult(A[i], A[i]), n)) % mod;
		F_A = (F_A - binMult(sum, sum) + mod) % mod;

		while (Q--) {
			int q_type;
			cin >> q_type;
			if (q_type == 1) {
				long long x, v;
				cin >> x >> v;
				update_F(F_A, A, n, sum, x, v);
				A[x] = v; 
			} else if (q_type == 2) {
				long long x, v;
				cin >> x >> v;
				update_F(F_A, A, n, sum, x, A[x] + v);
				A[x] += v; 
			} else {
				if (flag) cout << "Case " << r << ":" << endl;
				flag = 0;
				cout << F_A << endl;
			}
		}
	}

}