#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int N, K;
		cin >> N >> K;
		int max = 0;
		for (int i = 0; i < N; ++i)
		{
			int x;
			cin >> x;
			if (K-x > max)
				max = K-x;
		}
		cout << max << endl;
	}

}