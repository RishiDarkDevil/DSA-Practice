#include <bits/stdc++.h>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	int hash1[26] = {0}, hash2[26] = {0};

	if (str1.size() != str2.size())
		cout << false;
	for (int i = 0; i < str1.size(); ++i) {
		hash1[(int)str1[i]-97] ++;
		hash2[(int)str2[i]-97] ++;
	}
	for (int i = 0; i < 26; ++i) {
		if (hash1[i] != hash2[i])
			cout << false;
	}
	cout << true;
}