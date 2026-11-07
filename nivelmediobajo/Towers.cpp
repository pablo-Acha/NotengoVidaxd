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
    multiset<ll> ms;
    for (int i = 0; i < n; i++)
    {
        ll x;cin>>x;
        auto p = ms.upper_bound(x);
        if(p == ms.end()){
            ms.insert(x);
        }else{
            ms.erase(p);
            ms.insert(x);
        }
    }
    cout<<ms.size()<<"\n";
    return 0;
}