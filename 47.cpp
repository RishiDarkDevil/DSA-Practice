#include <bits/stdc++.h>
using namespace std;

long long int arr[10000000+10];

int main() {
	int n, q;
	cin >> n >> q;
	
	while (q--) {
		int a, b, k;
		cin >> a >> b >> k;
		arr[a] += k;
		arr[b+1] -= k;
	}

	for (int i = 1; i <= n; ++i)
		arr[i] += arr[i-1];

	long long int maxi = arr[1];
	for (int i = 1; i <= n; ++i) {
		if (maxi < arr[i])
			maxi = arr[i];
	}
	cout << maxi;
}