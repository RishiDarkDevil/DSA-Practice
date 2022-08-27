#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n,ans=0,p=1;
		cin >> n;
		for(int i=9;i;i--) {
			if(n>=i) {
				n-=i;
				ans+=p*i;
				p*=10;
			}
		}
		if(n) 
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
}