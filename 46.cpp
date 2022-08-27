#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int hash_table[1000] = {0};
	for (int i = 0; i < n; ++i)
		hash_table[arr[i]] ++;
	
	int num_rabs = 0;
	for (int i = 0; i < 1000; ++i) {
		if (hash_table[i] > 0) {
			int N = i+1; 
			int C = ceil((float)hash_table[i]/N);
			cout <<  "Grp Size: "<< N << ", #Cols: " << C << endl;
			num_rabs += (N*C);
		}
	}
	cout << num_rabs;
}