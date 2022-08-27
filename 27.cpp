#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int x; long long prod = 1; 
		for (int i = 0; i < n; ++i) {
			cin >> x;
			prod *= x;
		}
		int sig_dig = prod % 10;
		string like;
		if (((sig_dig == 2) || (sig_dig == 3) || (sig_dig == 5)))
			like = "YES";
		else
			like = "NO";
		cout << like << endl;
	}
}