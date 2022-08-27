#include <bits/stdc++.h>
using namespace std;

int hash_table[26][100000 + 10];

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, Q;
		cin >> N >> Q;

		string S;
		cin >> S;

		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < 100000+10; ++j)
				hash_table[i][j] = 0;
		}

		for (int i = 1; i <= N; ++i)
			hash_table[(int)S[i-1]-'a'][i] = 1;

		for (int i = 0; i < 26; ++i) {
			for (int j = 1; j <= N; ++j) {
				hash_table[i][j] += hash_table[i][j-1];
			}
		}

		while (Q--) {
			int L, R;
			cin >> L >> R;
			int odd_count = 0;
			for (int i = 0; i < 26; ++i) {
				if ((hash_table[i][R] - hash_table[i][L-1]) % 2 == 1)
					odd_count++;
			}
			if (((R-L+1) % 2 == 0) && (odd_count == 0))
				cout << "YES" << endl;
			else if (((R-L+1) % 2 == 1) && (odd_count == 1))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

}