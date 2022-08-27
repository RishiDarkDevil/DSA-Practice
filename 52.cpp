#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	unordered_map<string, int> name_count;
	while (n--) {
		string name;
		cin >> name;
		if (name_count[name]) {
			cout << name << name_count[name] << endl;
			name_count[name+to_string(name_count[name])]++;
			name_count[name]++;
		} else {
			name_count[name]++;
			cout << "OK" << endl;
		}
	}
}