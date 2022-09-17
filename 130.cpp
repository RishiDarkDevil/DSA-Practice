// https://atcoder.jp/contests/dp/tasks/dp_e

#include <bits/stdc++.h>
using namespace std;

vector<int> w, v;
// Carefully see that there are two states and see what is the range of values each state can take
// The value states can take maximum 10^5 and the index state can take maximum 100
long long dp[110][100010];


// For a given index and value return if the objects can be chosen in such a way that 
// it returns the minimum possible weight for making up that 'exact' value
long long minimize(int ind, int V, int N) {
	if (dp[ind][V] != -1) return dp[ind][V];
	if (V == 0) return 0;
	if (ind >= N) return 1e15;
	long long ans = 1e15, way1 = 1e15, way2 = 1e15; // Initially mistakenly set to 0 but see if 0
	// Then while taking min we can get 0 and later even if there is no weight that makes that value 
	// We will get a low value of weight whereas if the value is not possible to be made we should get large value 
	if (V - v[ind] >= 0) way1 = minimize(ind+1, V - v[ind], N) + w[ind];
	way2 = minimize(ind+1, V, N);
	ans = min(way1, way2);
	return dp[ind][V] = ans;
}

int main() {
	memset(dp, -1, sizeof(dp));

	int N, W;
	cin >> N >> W;
	
	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		w.push_back(x);
		v.push_back(y);
	}

	int max_value = 1e5;
	for (int i = max_value; i >= 0; --i) {
		if (minimize(0, i, N) <= W) {
			cout << i << endl;
			break;
		}
	}
}