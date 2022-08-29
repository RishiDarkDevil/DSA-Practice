#include <bits/stdc++.h>
using namespace std;

int find_gcd(int a, int b) { // Assume b > a
	int rem = b % a;
	if (rem == 0) return a;
	return find_gcd(rem, a);
}

int find_lcm(int a, int b) {
	return a * b / find_gcd(a, b);
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << find_gcd(a, b) << endl; // In-Built Function __gcd() available
	cout << find_lcm(a, b) << endl;

}