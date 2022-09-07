// https://leetcode.com/problems/flood-fill/

#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int init, int color, vector<vector<int>> &image, vector<vector<bool>> &visited) {
	if (i < 0 || j < 0) return;
	if (i >= image.size() || i >= image[0].size()) return;
	if (image[i][j] != init) return;
	if (visited[i][j]) return;

	visited[i][j] = true;
	image[i][j] = color;

	dfs(i, j-1, init, color, image, visited);
	dfs(i, j+1, init, color, image, visited);
	dfs(i-1, j, init, color, image, visited);
	dfs(i+1, j, init, color, image, visited);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
	vector<vector<bool>> visited;
	for (int i = 0; i < image.size(); ++i) {
		vector<bool> row;
		for (int j = 0; j < image[0].size(); ++j)
			row.push_back(false);
		visited.push_back(row);
	}
	dfs(sr, sc, image[sr][sc], color, image, visited);
	return image;
}

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> image;
	for (int i = 0; i < m; ++i) {
		vector<int> row;
		for (int j = 0; j < n; ++j) {
			int x;
			cin >> x;
			row.push_back(x);
		}
		image.push_back(row);
	}
	int sr, sc, color;
	cin >> sr >> sc >> color;

	vector<vector<int>> new_image = floodFill(image, sr, sc, color);
	for (auto &row: new_image) {
		for (auto cell: row)
			cout << cell << " ";
		cout << endl;
	}
}