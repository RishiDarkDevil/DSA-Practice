#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<int> graph[N];
bool visited[N];

void dfs(int v) {
	// Just entered root node
	visited[v] = true;
	for (auto &child: graph[v]) {
		// About to enter child nodes
		if (visited[child]) continue;
		dfs(child);
		// About to exit child nodes
	}
	// About to exit root node
}

int main() {
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	dfs(1);
}