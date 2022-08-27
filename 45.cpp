#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	map<long long, int> hash_table;
	long long sum = 0; int k = 0;
	hash_table[0] = 1;
	for (int i = 0; i < n; ++i) {
		sum += arr[i];
		if (hash_table[sum]) {
			k++;
			hash_table.clear();
			hash_table[0] = 1;
			sum = arr[i];
		}
		hash_table[sum]++;
	}

	cout << k;
}