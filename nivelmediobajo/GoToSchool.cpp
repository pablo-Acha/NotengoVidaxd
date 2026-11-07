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
    vector<pair<ll,ll>> v(n);   
    for (int i = 0; i < n; i++)
    {
        auto &[a,b] = v[i]; 
        cin>>a;
        b= i+1;
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n; i++)
    {
        cout<<v[i].second<<" ";
    }
    cout<<"\n";
        
    return 0;
}