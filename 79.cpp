#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	long long x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		long long y = sqrt(x);
		if (y*y != x) {
			cout << "NO" << endl;
			continue;
		}
		int flag = 0;
		int z = sqrt(y);
		for (int j = 2; j <= z; ++j) {
			if (y%j == 0) { 
				flag = 1;
				break;
			}
		}
		if (flag == 0 && x > 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

}