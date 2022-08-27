#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int x[n-1], arr[n];

		for (int i = 0; i < n; ++i)
			arr[i] = 1;
		
		for (int i = 0; i < n-1; ++i)
			cin >> x[i];

		for (int i = 1; i < n; ++i) {
			if (x[i-1] == 0) {
				arr[i] = arr[i-1];
			} else if (x[i-1] == 1) {
				arr[i] = arr[i-1] + 1;
			} else {
				arr[i] = 1;
				if (arr[i-1] <= arr[i]){
					arr[i-1] += 1;
					int l = i-1;
					while (l >= 1) {
						if (x[l-1] == 0) {
							arr[l-1] += 1;
						} else if (x[l-1] == 2 && arr[l] >= arr[l-1]) {
							arr[l-1] += 1;
						} else {
							break;
						}
						l--;
					}
				}
			}
		}
		
		for (int i = 0; i < n; ++i)
			cout << arr[i] << " ";
		cout << endl;
	}
}