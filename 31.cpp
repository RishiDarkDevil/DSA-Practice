#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	int a = 1, b = 1;
	int term;
	for (int i = 0; i < C; ++i) {
		int mult_A = A*a;
		int mult_B = B*b;
		if (mult_A < mult_B) {
			a++;
			term = mult_A;
			if (mult_B % A == 0)
				b++;
		}
		else if (mult_B < mult_A) {
			b++;
			term = mult_B;
			if (mult_A % B == 0)
				a++;
		}
		else {
			term = mult_A;
			a++; b++;
		}
	}
	int step = lcm(A, B);
	if ((term % A == 0) && (term % B != 0))
		step = A;
	if ((term % A != 0) && (term % B == 0))
		step = B;
	while (term >= 0) {
		cout << term << " ";
		term -= step;
	}
}