#include <bits/stdc++.h>
using namespace std;

int main() {
	string sent;
	getline(cin, sent);
	sent.push_back(' ');
	string part = "";
	for (int i = 0; i < sent.size(); ++i)
	{
		char ch = sent[i];
		if (ch == ' ') {
			cout << part << endl;
			part = "";
			continue;
		}
		part.push_back(toupper(ch));
	}
}