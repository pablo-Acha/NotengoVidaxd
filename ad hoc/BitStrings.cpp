#include<bits/stdc++.h>
using namespace std;
long long MOD  = 1e9+7;
int main(){
    long long n;cin>>n;
    long long res = 1;
    long long a = 2;
    while (n)
    {
        if(n&1)res=(res*a)%MOD;
        a=(a*a)%MOD;
        n/=2;
    }
    cout<<res<<"\n";
    return 0;
}