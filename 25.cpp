#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int x, k = 0;
		int min_speed = INT_MAX;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			if (x <= min_speed) { 
				min_speed = x;
				k++;
			}
		}

		cout << k << endl;
	}
}