#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int b1, b2, n;
		cin >> b1 >> b2 >> n;
		int x, price1 = 0, price2 = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 2; ++j) {
				cin >> x;
				price1 += x*b1*(1-j) + x*b2*j;
				price2 += x*b2*(1-j) + x*b1*j;
			}
		}
		cout << min(price1, price2) << endl;
	}
}