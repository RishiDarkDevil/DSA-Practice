#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int N;
		cin >> N;
		cin.ignore();
		int A[N][N];
		for (int i = 0; i < N; ++i){
			string s;
			getline(cin, s);
			for (int j = 0; j < N; ++j)
				A[i][j] =  (int)s[j] - 48;
		}
		int flag = 1;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if ((A[i][j] != A[i][N-j-1]) || (A[i][j] != A[N-i-1][j])){
					flag = 0;
					break;
				}
			}
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}