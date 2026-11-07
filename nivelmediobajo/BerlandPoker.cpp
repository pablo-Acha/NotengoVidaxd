#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,m,k;cin>>n>>m>>k;
        ll x = n/k;
        if(m<=x){
            cout<<m<<"\n";
        }else{
            ll res = x-(((m-x)/(k-1)) + ((m-x)%(k-1) > 0));
            cout<<res<<"\n";
        }
    }

    return 0;
}