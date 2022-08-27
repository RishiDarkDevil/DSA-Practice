#include <bits/stdc++.h>
using namespace std;

int area(pair<int, int> p1, pair<int, int> p2) {
	return abs((p1.first - p2.first)*(p1.second-p2.second));
}

int main() {
	int n;
	cin >> n;

	set<pair<int, int>> points;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		points.insert({x, y});
	}
	int max_area = -1, min_area = INT_MAX; 
	for (auto &p1: points) {
		for (auto &p2: points) {
			if (points.find({p1.first, p2.second}) != points.end() && points.find({p2.first, p1.second}) != points.end() && p1.first != p2.first && p1.second != p2.second) {
				max_area = max(max_area, area(p1, p2));
				min_area = min(min_area, area(p1, p2));
			}
		}
	}
	if (max_area != -1)
		cout << (max_area - min_area);
	else
		cout << -1;
}