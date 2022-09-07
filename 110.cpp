// https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3; 
vector<int> graph[N];
vector<bool> visited(N, false);

void dfs(int v) {
	visited[v] = true;
	for (auto &child: graph[v]) {
		if (visited[child]) continue;
		dfs(child);
	}
}

int main() {
	int n, e;
	cin >> n >> e;
	for (int i = 0; i < e; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	int cnt_cmps = 0;
	for (int v = 1; v <= n; ++v) {
		if (visited[v]) continue;
		dfs(v);
		cnt_cmps++;
	}
	cout << cnt_cmps;
}