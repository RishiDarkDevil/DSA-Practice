#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long int prod = 1;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		prod = (prod*k) % 1000000007;
	}
	cout << prod; 
}