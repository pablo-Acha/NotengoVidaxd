#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

ll f(ll n,ll x,ll y, ll px, ll py){
    ll prd = 0;
    if(x== px){
        // cout<<"xxx\n";
        return 0;
    }
    if(x>px){
        prd = n;
    }
    prd = abs(prd-x);
    // prd = abs(prd-px)-min(abs(prd-px),abs(y-py));
    // cout<<prd<<"\n";
    // cout<<abs(px-x)<<"\n";
    // cout<<min(abs(prd-px),abs(y-py))<<"\n -------\n";
    return prd +abs(px-x);
}


const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,x,y,px,py;cin>>n>>y>>x>>py>>px;
        ll res = max(f(n,x,y,px,py),f(n,y,x,py,px));
        // cout<<f(n,x,y,px,py)<<" "<< f(n,y,x,py,px)<<"\n" ;
        cout<<res<<"\n";
    }
    return 0;
}