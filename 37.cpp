#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	priority_queue <int, vector<int>, greater<int> > subarr;

	for (int i = 0; i < k; ++i)
		subarr.push(arr[i]);

	for (int i = k; i < n; ++i) {
		if (arr[i] > subarr.top()){
			subarr.pop();
			subarr.push(arr[i]);
		}
	}

	int sum = 0;
	while (subarr.empty() == false) {
		sum += subarr.top();
		cout << subarr.top() << endl;
		subarr.pop();
	}

	cout << sum << endl;
}