#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    long long res = 0;
    long long mx= 0;
    for (int i = 0; i < n; i++)
    {
        long long a,b;cin>>a>>b;
        res -= a;
        res += b;
        mx =max(mx,res);
        // cout<<mx<<"\n";
    }
    cout<<mx<<"\n";
    return 0;
}