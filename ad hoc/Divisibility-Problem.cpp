#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        long long a,b;cin>>a>>b;
        long long mod = a%b;
        if(mod == 0){
            cout<<0<<"\n";
            continue;
        }
        long long res = b-mod;
        cout<<res<<"\n";
    }
    return 0;
}