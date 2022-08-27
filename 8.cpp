#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n % 2 == 0)
		cout << max(((n/2)-1)/2, 0);
	else 
		cout << 0;
}