#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		int flag = 0;
		for (int i = 97; i < 123; ++i) {
			int c = 0;
			for (int j = 0; j < str.size(); ++j) {
				if ((int)str[j] == i)
					c++;
			}
			if (c > 1){
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}