// https://codeforces.com/contest/1728/problem/B

#include <bits/stdc++.h>
using namespace std;

int main() { 
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n & 1) {
			for (int i = 1; i <= ((n-3)/2)-1; ++i)
				cout << 2*i + 1 << " " << 2*i << " ";
			cout << n-1 << " " << n-3 << " " << 1 << " " << n-2 << " " << n << endl;
		}  else {
			if (n == 4) {
				cout << 2 << " " << 1 << " " << 3 << " " << 4 << endl;
				continue;
			}
			if (n == 6) {
				cout << 4 << " " << 5 << " " << 1 << " " << 2 << " " << 3 << " " << 6 << endl;
				continue;
			}
			for (int i = 1; i <= ((n-4)/2)-2; ++i)
				cout << 2*i + 2 << " " << 2*i + 1 << " ";
			cout << n-3 << " " << n-5 << " " << n-1 << " " << n-2 << " " << 1 << " " << 2 << " " << n-4 << " " << n << endl;
		}
	}
}