#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

ll gaus(ll n){
    return (n*(n+1))/2;
}

ll conta = 0;
ll fun(ll in,ll fn,ll k, map<ll,ll> &mp){
    ll n = fn-in+1;
    if(n<k)return 0;
    if(mp.find(n) != mp.end()){
        return mp[n] + (conta * (in-1));
    }
    // if(conta== 10)return 0;
    // conta++;
    ll m = ((in+fn)/2);
    if(n&1){
        if(n == 1){
            mp[n] = 1;
        }else{
            mp[n] = m + fun(in,m-1,k, mp)+fun(m+1,fn,k,mp); 
        }
    }else{
        mp[n] = fun(in,m,k, mp)+fun(m+1,fn,k,mp); 
    }
    conta  = conta*2 +(n&1);


    return mp[n];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tt;cin>>tt;
    while(tt--)
    {   
        conta = 0;
        ll n,k;cin>>n>>k;
        map<ll,ll> mp;
        ll res = fun(1LL,n,k,mp);
        // for(auto [x,v]:mp){
        //     cout<<x<<" "<<v<<"\n";
        // }
        cout<<res<<"\n";
    }

    return 0;
}