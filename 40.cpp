#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int hash[4] = {0};
		string str;
		cin >> str;

		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == 'r')
				hash[0]++;
			if (str[i] == 'u')
				hash[1]++;
			if (str[i] == 'b')
				hash[2]++;
			if (str[i] == 'y')
				hash[3]++;
		}
		int mini = hash[0];
		for (int i = 0; i < 4; ++i)
			mini = min(mini, hash[i]);
		cout << mini << endl;
	}
}