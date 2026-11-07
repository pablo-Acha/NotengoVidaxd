#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll gaus(ll n){
    return (n*(n+1))/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;cin>>n;
    map<string,ll> mp;    
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        mp[s]++;
    }
    ll res = 0;
    for(auto [s,v]:mp){
        res+= gaus(v-1);
    }
    cout<<res<<"\n";
    return 0;   
}