#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
ll val(ll n, ll j,ll ul){
    ll com = 0;
    while(j){
        j--;
        com = (com*10) +ul;
    }
    return n>=com;
}   

int main(){
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        map<ll,ll> mp;
        map<ll,ll> mp1;
        for (ll i = 0,a; i < n; i++)
        {
            cin>>a;
            mp[a]++;
            if(mp1.find(a) == mp1.end()){
                mp1[a] = i+1;
            }
            
        }
        ll mn  = 1e9;
        ll res = 0;
        for(auto [a,b]:mp){
            if(mn>b){
                res  = a;
                mn = b;
            }
        }
        cout<<mp1[res]<<"\n";
    }
    return 0;
}