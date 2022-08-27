// https://www.spoj.com/problems/PIE/

#include <bits/stdc++.h>
using namespace std;

bool isPieVolSuff(double Vols[], int N, int F, double V) {
	int k = 0;
	for (int i = 0; i < N; ++i)
		k += (int)(Vols[i]/V);
	return k >= F;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int N, F;
		cin >> N >> F;
		F++;

		int R[N]; double Vols[N];
		double max_vol = DBL_MIN;
	 	for (int i = 0; i < N; ++i) {
			cin >> R[i];
			double vol = M_PI*pow(R[i], 2);
			max_vol = max(max_vol, vol);
			Vols[i] = vol;
		}



		double lo = 0, hi = max_vol, eps = 1e-4, mid = 0.0;
		while (hi - lo  > eps) {
			mid = (hi + lo) / 2;
			if (isPieVolSuff(Vols, N, F, mid))
				lo = mid;
			else
				hi = mid;
		}
		cout << setprecision(4) << fixed << lo << endl;
	}
}