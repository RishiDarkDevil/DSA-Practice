    #include<iostream>
    #include<bits/stdc++.h>
     
    using namespace std;
    int main()
    {
    int t;
    cin >> t;
    while(t--)
    {
     int n;
     cin >> n;
     string s;
     cin >> s;
     int len = s.length();
     long long int dec = 0;
     long long int p=0;
     for(int i=n-1;i>=0;--i)
     {
      if(s[i]=='1')
      {
       dec = dec +  1*(pow(2,(len-1-i)));
      }
     }
     cout << dec << '\n';
     
    }
    }