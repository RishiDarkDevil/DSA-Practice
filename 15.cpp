#include <bits/stdc++.h>
using namespace std;

int main() {
	string command, part = "", output = "";
	cin >> command;
	for (int i = 0; i < command.size(); i++)
	{
		if (command[i] == '(') {
			continue;
		}
		else if (command[i] == ')'){
			if (part == "")
				output.push_back('o');
			else
				output += "al";
			part = "";
		}
		else {
			part.push_back(command[i]);
		}
		if (command[i] == 'G') {
			output.push_back('G');
			part = "";
		}
	}
	cout << output;
}