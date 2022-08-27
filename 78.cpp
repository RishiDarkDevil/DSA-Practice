#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n;
		multiset<int> arr1;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			arr1.insert(x);
		}
		cin >> m;
		int arr2[m];
		for (int i = 0; i < m; ++i)
			cin >> arr2[i];

		for (int i = 0; i < m; ++i) {
			auto it = arr1.find(arr2[i]);
			if (it != arr1.end()) {
				for (auto j = it; j != arr1.end(); ++j) {
					if (*j == arr2[i]) 
						cout << *j << " ";
					else
						break;
				}
				arr1.erase(arr2[i]);
			}
		}
		for (auto &i: arr1)
			cout << i << " ";
		cout << endl;
	}
}