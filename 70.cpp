#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; string str;
	cin >> n >> str;

	int flag = 0, k = 0, ans = 0;

	for (int i = 0; i < n; ++i) {
		if (str[i] == 'b') {
			if (flag) ans += k;
			flag = 0; k = 0;
		} else {
			if (str[i] == 'a') flag = 1;
			k++;
		}
	}
	if (str[n-1] != 'b' && flag == 1) ans += k;
	cout << ans;
}