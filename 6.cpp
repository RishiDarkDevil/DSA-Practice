#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	if ((n/2 > 1) && (2*(n/2) == n))
		cout << "YES";
	else
		cout << "NO";
}