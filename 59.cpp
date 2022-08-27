#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	while (n--) {
		string exp;
		cin >> exp;

		stack<char> brackets;
		for (int i = 0; i < exp.size(); ++i) {
			if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
				brackets.push(exp[i]);
			else {
				if (!brackets.empty() && ((exp[i] == ')' && brackets.top() == '(') || (exp[i] == '}' && brackets.top() == '{') || (exp[i] == ']' && brackets.top() == '[')))
					brackets.pop();
				else
					break;
			}
		}
		if (brackets.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}