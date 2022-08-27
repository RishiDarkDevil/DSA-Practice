#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		unsigned long long int sum = 0;
		string number; 
		cin >> number;
		long long int p = 1;
		for (int i = n-1; i >= 0; i--) {
			// cout << sum << " " << number[i] << " ";
			if (number[i] == '1')
				sum += 1*p;
			p *= 2;
			// cout << sum << endl;
			// cout << fixed << sum + (int)1*pow(2,(n-i-1)) << endl;
		}

		cout << sum << endl;
	}
}