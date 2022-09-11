#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<int> g[N];
int parent[N];

void dfs(int vertex, int par=0) {
	parent[vertex] = par;
	for (auto &child: g[vertex]) {
		if (child == par) continue;
		dfs(child, vertex);
	}
}

vector<int> path(int v) {
	vector<int> ans;
	ans.push_back(v);
	while (parent[ans[ans.size()-1]] != 0)
		ans.push_back(parent[ans[ans.size()-1]]);
	reverse(ans.begin(), ans.end());
	return ans;
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

	int x, y;
	cin >> x >> y;
	vector<int> path_x = path(x);
	vector<int> path_y = path(y);

	int LCA = 0;
	for (int i = 0; i < min(path_x.size(), path_y.size()); ++i) {
		if (path_x[i] == path_y[i]) 
			LCA = path_x[i];
		else
			break;
	}
	cout << LCA;
}