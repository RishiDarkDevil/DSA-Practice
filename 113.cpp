// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?category=

#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
	int m = grid.size();
	int n = grid[0].size();
	if (i < 0 || j < 0) return;
	if (i >= m || j >= n) return;
	if (grid[i][j] == '0') return;
	if (visited[i][j]) return;
	
	visited[i][j] = true;
	dfs(i, j-1, grid, visited);
	dfs(i, j+1, grid, visited);
	dfs(i+1, j, grid, visited);
	dfs(i-1, j, grid, visited);
	dfs(i+1, j-1, grid, visited);
	dfs(i+1, j+1, grid, visited);
	dfs(i-1, j-1, grid, visited);
	dfs(i-1, j+1, grid, visited);

}

int numIslands(vector<vector<char>> &grid) {
	vector<vector<bool>> visited;
	for (int i = 0; i < grid.size(); ++i) {
		vector<bool> row;
		for (int j = 0; j < grid[0].size(); ++j)
			row.push_back(false);
		visited.push_back(row);
	}

	int ct = 0;
	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid[0].size(); ++j) {
			if (visited[i][j] || grid[i][j] == '0') continue;
			dfs(i, j, grid, visited);
			ct++;
		}
	}
	return ct;
}

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<char>> grid;
	for (int i = 0; i < m; ++i) {
		vector<char> row;
		for (int j = 0; j < n; ++j) {
			char x;
			cin >> x;
			row.push_back(x);
		}
		grid.push_back(row);
	}

	cout << numIslands(grid);
}