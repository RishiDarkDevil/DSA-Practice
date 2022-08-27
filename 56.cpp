#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		unordered_set<long long> stud_candies;
		for (int i = 0; i < n; ++i) {
			long long candy;
			cin >> candy;
			stud_candies.insert(candy);
		}
		for (int i = 0; i < m; ++i) {
			long long incomining;
			cin >> incomining;
			if (stud_candies.find(incomining) != stud_candies.end())
				cout << "YES" << endl;
			else 
				cout << "NO" << endl;
			stud_candies.insert(incomining);
		}
	}

}