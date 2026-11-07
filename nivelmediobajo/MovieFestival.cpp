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
    vll in(n),fn(n),val(n),aux(n);
    iota(aux.begin(),aux.end(),0);
    for (ll i = 0; i < n; i++)
    {
        cin>>in[i]>>fn[i];
    }
    sort(aux.begin(),aux.end(),[&](int i,int j){
        return in[i]<in[j];
    });
    sort(in.begin(),in.end());
    ll mn = 1e10;
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        ll p = lower_bound(in.begin(),in.end(),fn[aux[i]])-in.begin();
        if(i>=mn){res++;mn = 1e10;}
        // cout<<mn<<"\n";
        mn = min(p,mn);
    }
    cout<<res+(mn>=n)<<"\n";
    return 0;
}