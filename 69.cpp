#include <bits/stdc++.h>
using namespace std;

int long_substr(string &str, int start, int end, int k) {
	if (end < k) return 0;
	int countmap[26] = {0};

	for (int i = start; i < end; ++i)
		countmap[str[i] - 'a']++;

	for (int i = start; i < end; ++i) {
		if (countmap[str[i] - 'a'] >= k) continue;
		int midNext = i+1;
		while (midNext < end && countmap[str[midNext] - 'a'] < k) midNext++;
		return max(long_substr(str, start, i, k), long_substr(str, midNext, end, k));
	}
	return end - start;
}

int main() {
	string str;
	cin >> str;

	int k;
	cin >> k;

	cout << long_substr(str, 0, str.size(), k);
}