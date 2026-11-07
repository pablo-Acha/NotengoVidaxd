#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        long long a,b;cin>>a>>b;
        long long mn  = min(a,b);
        long long mx = max(a,b);
        long long y = mn*2;
        long long res = max(y,mx);
        cout<<res*res<<"\n";
    }

    return 0;
}