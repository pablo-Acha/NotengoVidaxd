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
    map<ll,ll> mp;
    for (int i = 0,a,b; i < n; i++)
    {
        cin>>a>>b;
        mp[a]++;
        mp[b+1]--;
    }
    ll mx = 0,aux = 0;
    for(auto [a,b]:mp){
        aux+=b;
        mx = max(aux,mx);
    }
    cout<<mx<<"\n";
    return 0;
}