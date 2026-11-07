#include<bits/stdc++.h>
using namespace std;
long long MOD  = 1e9+7;
typedef long long ll;
int main(){
    ll n;cin>>n;
    ll h =5;
    ll res =0;  
    while(h<=n){
        res+= n/h;
        h*=5;
    }
    cout<<res<<"\n";
    return 0;
}