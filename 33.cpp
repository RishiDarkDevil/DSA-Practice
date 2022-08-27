#include <bits/stdc++.h>

 

using namespace std;

void printPascal(long long n)

{

for (long long i=1;i<=n;i++)

{

long long c=1;

for (long long j=1;j<=i;j++)

{

cout<<c<<" ";

c=c*(i-j)/j;

}

cout<<"\n";

}

}

 

int main()

{

int t;

cin>>t;


 

while(t--)

{

long long n;

cin>>n;

printPascal(n);

}

return 0;

}
