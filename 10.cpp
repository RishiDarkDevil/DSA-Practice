#include<bits/stdc++.h>
using namespace std;

int main() {
	long long int n;
	cin >> n;
	if (n % 2 == 0) {
		if ((n-4) % 4 == 0)
			cout << 0;
		else
			cout << 1;
	}
	else {
		if ((n-3) % 4 == 0)
			cout << 0;
		else
			cout << 1;
	}
}