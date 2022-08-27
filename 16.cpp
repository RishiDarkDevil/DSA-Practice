#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string str; int n;
		cin >> n;
		cin >> str;
		int k = 1;
		for (int i = 0; i < n-1; i++) {
			if (str[i] != str[i+1])
				k++;
		}
		cout << k << endl;
	}
}