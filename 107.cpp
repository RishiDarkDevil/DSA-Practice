// https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/xor-challenge-2420f189/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int C;
	cin >> C;
	int bit_cnt_c = (int)log2(C) + 1;
	int A = 0, B = 0;
	vector<int> set_bits;
	for (int i = 0; i < bit_cnt_c; ++i) {
		if (C & (1 << i))
			set_bits.push_back(i);
		else {
			A |= (1 << i);
			B |= (1 << i);
		}
	}
	long long ans = -1;
	for (int mask = 0; mask < (1 << set_bits.size()); ++mask) {
		int A_copy = A, B_copy = B;
		for (int i = 0; i < set_bits.size(); ++i) {
			if (mask & (1 << i))
				A_copy |= (1 << set_bits[i]);
			else
				B_copy |= (1 << set_bits[i]);
		}
		ans = max(ans, A_copy * 1LL * B_copy);
	}
	cout << ans;
}