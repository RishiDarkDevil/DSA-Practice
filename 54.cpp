#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		multiset<long long int> candies;
		for (int i = 0; i < n; ++i) {
			long long int candy_ct;
			cin >> candy_ct;
			candies.insert(candy_ct);
		}

		long long int answer = 0;
		for (int i = 0; i < k; ++i) {
			auto last_it = (--candies.end());
			long long last_candy_ct = (*last_it);
			answer += last_candy_ct;
			candies.erase(last_it);
			candies.insert(last_candy_ct/2);
		}
		
		cout << answer << endl;
	}
}