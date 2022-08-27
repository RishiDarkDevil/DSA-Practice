#include <bits/stdc++.h>
using namespace std;

int isprime(int n){
	int facts = 0;
	for (int i = 1; i < n; ++i) {
		if (n % i == 0)
			facts++;
	}
	return (facts == 1);
}

int main() {
	string str;
	cin >> str;
	long long int upper = 0, lower = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (isupper(str[i]))
			upper -= (int)tolower(str[i]);
		if (islower(str[i]))
			lower += (int)toupper(str[i]);
	}
	int diff = abs(upper + lower);
	cout << isprime(diff);
}