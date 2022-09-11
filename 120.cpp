#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<int> g[N];
int subtree_sum[N];
int even_ct[N];

void dfs(int vertex, int par=0) {

	if (vertex % 2 == 0) even_ct[vertex]++;
	for (auto &child: g[vertex]) {
		if (child == par) continue;
		dfs(child, vertex);
		subtree_sum[vertex] += subtree_sum[child];
		even_ct[vertex] += even_ct[child];
	}
	subtree_sum[vertex] += vertex;
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

	for (int i = 1; i <= n; ++i)
		cout << i << " " << subtree_sum[i] << " " << even_ct[i] << endl;
}