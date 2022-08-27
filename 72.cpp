#include <bits/stdc++.h>
using namespace std;

int num_stop_islands(vector<pair<int, int>> &D_A, int K, int F, int i) {
	cout << K << " " << F << " " << i << endl;
	if (F <= 0 && K > 0) return -1;
	if (F >= K) return 0;
	int choose1, choose2;
	if (F-(K-D_A[i].first) < 0) 
		return -1;
	else
		choose1 = 1 + num_stop_islands(D_A, D_A[i].first, F-(K-D_A[i].first)+D_A[i].second, i+1);
	if (F-(K-D_A[i+1].first) >= 0)
		choose2 = 1 + num_stop_islands(D_A, D_A[i].first, F-(K-D_A[i+1].first)+D_A[i+1].second, i+2);
	else
		choose2 = INT_MAX;
	return min(choose1, choose2);
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
			D_A.push_back({d, a});
		}
		D_A.push_back({0, 0});

		sort(D_A.begin(), D_A.end(), greater<pair<int, int>> ());

		cout << num_stop_islands(D_A, K, F, 0) << endl;
	}

}