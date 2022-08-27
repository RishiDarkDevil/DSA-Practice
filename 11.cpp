#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (2*n)-1; j++)
		{
			if (j <= i)
				cout << n-j;
			else if (j >= (2*n)-i-1)
				cout << j-n+2;
			else
				cout << n-i;
		}
		cout << endl;
	}
	for (int i = n-2; i > 0; i--)
	{
		for (int j = 0; j < (2*n)-1; j++)
		{
			if (j <= i)
				cout << n-j;
			else if (j >= (2*n)-i-1)
				cout << j-n+2;
			else
				cout << n-i;
		}
		cout << endl;
	}
	if (n > 1)
	{
		for (int i = 0; i < (2*n)-1; i++)
			cout << n;
	}
}