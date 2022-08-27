#include <bits/stdc++.h>
using namespace std;

int main() {
	string str1, str2; int n;
	cin >> n;
	cin >> str1 >> str2;
	int i = 0;
	for (i = 0; i < n; i++){
		if (str1.substr(i) == str2.substr(0, n-i)) {
			break;
		}
	}
	cout << i;
}