// https://leetcode.com/problems/pacific-atlantic-water-flow/

#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &heights, vector<vector<bool>> &visited) {
	if (i < 0 || j < 0) return;
	if (i >= heights.size() || j >= heights[0].size()) return;
	if (visited[i][j]) return;

	visited[i][j] = true;

	if (j >= 1) {
		if (heights[i][j-1] >= heights[i][j])
			dfs(i, j-1, heights, visited);
	}
	if (j < heights[0].size()-1) {
		if (heights[i][j+1] >= heights[i][j])
			dfs(i, j+1, heights, visited);
	}
	if (i >= 1) {
		if (heights[i-1][j] >= heights[i][j])
			dfs(i-1, j, heights, visited);
	}
	if (i < heights.size()-1) {
		if (heights[i+1][j] >= heights[i][j])
			dfs(i+1, j, heights, visited);
	}
}

vector<vector<bool>> pacific(vector<vector<int>> &heights) {
	vector<vector<bool>> visited;
	for (int i = 0; i < heights.size(); ++i) {
		vector<bool> row;
		for (int j = 0; j < heights[0].size(); ++j)
			row.push_back(false);
		visited.push_back(row);
	}

	// Find flow towards Pacific
	for (int i = 0; i < heights.size(); ++i) {
		dfs(i, 0, heights, visited);
	}
	for (int i = 0; i < heights[0].size(); ++i) {
		dfs(0, i, heights, visited);
	}

	return visited;
}

vector<vector<bool>> atlantic(vector<vector<int>> &heights) {
	vector<vector<bool>> visited;
	for (int i = 0; i < heights.size(); ++i) {
		vector<bool> row;
		for (int j = 0; j < heights[0].size(); ++j)
			row.push_back(false);
		visited.push_back(row);
	}

	// Find flow towards Atlantic
	for (int i = 0; i < heights.size(); ++i) {
		dfs(i, heights[0].size()-1, heights, visited);
	}
	for (int i = 0; i < heights[0].size(); ++i) {
		dfs(heights.size()-1, i, heights, visited);
	}
	return visited;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
	vector<vector<int>> ans;
	if (heights.size() == 1 || heights[0].size() == 1) {
		for (int i = 0; i < heights.size(); ++i) {
			for (int j = 0; j < heights[0].size(); ++j) {
				vector<int> cell;
				cell.push_back(i);
				cell.push_back(j);
				ans.push_back(cell);
			}
		}
		return ans;
	}

	vector<vector<bool>> ans1 =  pacific(heights);
	vector<vector<bool>> ans2 =  atlantic(heights);
	for (int i = 0; i < ans1.size(); ++i) {
		for (int j = 0; j < ans1[0].size(); ++j) {
			if (ans1[i][j] & ans2[i][j]) {
				vector<int> cell;
				cell.push_back(i);
				cell.push_back(j);
				ans.push_back(cell);
			}
		}
	}

	return ans;
}

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> heights;
	for (int i = 0; i < m; ++i) {
		vector<int> row;
		for (int j = 0; j < n; ++j) {
			int x;
			cin >> x;
			row.push_back(x);
		}
		heights.push_back(row);
	}

	vector<vector<int>> ans = pacificAtlantic(heights);
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[0].size(); ++j)
			cout << ans[i][j] << " ";
		cout << endl;
	}
}