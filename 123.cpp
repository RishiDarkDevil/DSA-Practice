// https://www.interviewbit.com/problems/delete-edge/

#include <bits/stdc++.h>
using namespace std;

void dfs(int vertex, int par, vector<int> &val, vector<vector<int>> &g, int subtree_sum[]) {

	for (auto &child: g[vertex]) {
		if (child == par) continue;
		dfs(child, vertex, val, g, subtree_sum);
		subtree_sum[vertex] += subtree_sum[child];
	}
	subtree_sum[vertex] += val[vertex];
}

int deleteEdge(vector<int> &A, vector<vector<int> > &B) {
	vector<vector<int>> g;
	for (int i = 0; i < A.size()+10; ++i) {
		vector<int> x;
		g.push_back(x);
	}
	for (auto &edge: B) {
		g[edge[0]].push_back(edge[1]);
		g[edge[1]].push_back(edge[0]);
	}

	vector<int> val(A.size()+10, 0);
	for (int i = 1; i <= A.size(); ++i)
		val[i] = A[i-1];

	int subtree_sum[A.size()+10] = {0};
	dfs(1, 0, val, g, subtree_sum);

	long long max_prod = -1;
	for (int i = 2; i <= A.size(); ++i)
		max_prod = max(max_prod, ((subtree_sum[1]-subtree_sum[i]) * 1LL * subtree_sum[i]) % 1000000007);
	return max_prod;
}

int main() {
	int n;
	cin >> n;
	vector<int> A;
	for (int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		A.push_back(val);
	}
	vector<vector<int>> B;
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		cin >> x >> y;
		vector<int> edge;
		edge.push_back(x);
		edge.push_back(y);
		B.push_back(edge);
	}
	cout << deleteEdge(A, B);
}