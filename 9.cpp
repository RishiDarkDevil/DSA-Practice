#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 2*n; j++)
			{
				if ((j <= i) || (j >= (2*n-i-1)))
					cout << "*";
				else
					cout << "#";
			}
			cout << endl;
		}
		cout << endl;
	}
}