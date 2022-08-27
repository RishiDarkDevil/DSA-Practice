#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int A[N+1];
	for (int i = 1; i < N+1; ++i)
		cin >> A[i];
	A[0] = A[N];
	for (int i = 0; i < N; ++i)
		cout << A[i] << " ";
}