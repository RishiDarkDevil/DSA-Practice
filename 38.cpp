#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> arr;
	unordered_set<int> dup_check;

	for (auto i = arr.begin(); i != arr.end(); ++i) {
		if (dup_check.find(*i) == dup_check.end())
			dup_check.insert(*i);
		else
			return true;
	}
	return false;
}