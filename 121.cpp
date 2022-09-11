#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<int> g[N];
int depth[N];

void dfs(int vertex, int par = 0) {

	for (auto &child: g[vertex]) {
		if (child == par) continue;
		depth[child] = depth[vertex] + 1;
		dfs(child, vertex);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1);
	
	int max_depth = -1;
	int max_node = -1;
	for (int i = 1; i <= n; ++i) {
		if (depth[i] > max_depth) {
			max_depth = depth[i];
			max_node = i;
		}
		depth[i] = 0;
	}

	dfs(max_node);
	for (int i = 1; i <= n; ++i)
		max_depth = max(max_depth, depth[i]);
	cout << max_depth << endl;
}