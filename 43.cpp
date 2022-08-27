#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string patt, str;
		cin >> patt >> str;

		multiset<char> patt_not_used;
		multiset<char> patt_used;
		for (int i = 0; i < patt.size(); ++i)
			patt_not_used.insert(patt[i]);

		int k = 0, i = 0;
		while (i < str.size()) {

			auto itr = patt_not_used.find(str[i]);
			if (itr != patt_not_used.end()) {
				k++;
				patt_not_used.erase(itr);
				patt_used.insert(str[i]);
				if (patt_not_used.empty())
					break;
			} else {
				for (auto j = patt_used.begin(); j != patt_used.end(); j++)
					patt_not_used.insert(*j);
				patt_used.clear();
				i -= k;
				k = 0;
			}
			i++;
		}
		if (patt_not_used.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}