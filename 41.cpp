#include <bits/stdc++.h>
using namespace std;

int main() {
	string pattern, s;
	cin >> pattern;

	int n = pattern.size();
	string words[n];
	
	int k = 0;
	while(true) {
		string str;
		cin >> str;
		if (str != ""){
			if (k < n)
				words[k++] = str;
			else{
				cout << "false";
				return 0;
			}
		} else
			break; 
	}
	if (k < n) {
		cout << "false";
		return 0;
	}
	
	map<char, string> word_char_map;
	unordered_set<string> word_used;
	for (int i = 0; i < n; ++i) {
		auto itr = word_char_map.find(pattern[i]);
		if (itr != word_char_map.end()) {
			if ((itr->second != words[i])) {
				cout << "false";
				return 0;
			}
		}
		else {
			if (word_used.find(words[i]) == word_used.end()) {
				word_used.insert(words[i]);
				word_char_map.insert({pattern[i], words[i]});
			}
			else {
				cout << "false";
				return 0;
			}
		}
	}
	cout << "true";

}