#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	string plan;
	cin >> plan;

	unordered_map<char, int> key_count;
	int ans = 0;
	for (int i = 0; i < 2*n-2; i += 2) {
		key_count[plan[i]]++;
		if (key_count[tolower(plan[i+1])])
			key_count[tolower(plan[i+1])]--;
		else
			ans++;
	}
	cout << ans;
}