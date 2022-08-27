#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	
	unordered_map<int, int> NGE;
	stack<int> st;
	for (int i = 0; i < n; ++i) {
		while (!st.empty()) {
			if (arr[i] > st.top()) {
				NGE[st.top()] = arr[i];
				st.pop();
			} else 
				break;
		}
		st.push(arr[i]);
	}
	while(!st.empty()) {
		NGE[st.top()] = -1;
		st.pop();
	}
	for (auto &i: arr)
		cout << i << " " << NGE[i] << endl;
}