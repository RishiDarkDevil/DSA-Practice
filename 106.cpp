// https://www.hackerearth.com/problem/algorithm/monk-and-his-father-93b639f4/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long p;
		cin >> p;
		cout << __builtin_popcountll(p) << endl;
	}
}