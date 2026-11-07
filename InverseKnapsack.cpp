#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;cin>>n>>m;
    vll arr(n),brr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i]>>brr[i];
    }
    map<ll,ll> mp;
    mp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        map<ll,ll> aux;
        for(auto [k,v]:mp){
            aux[k+arr[i]] = v+brr[i];
        } 
        for(auto [k,v]:aux){
            if(mp.find(k) == mp.end())
            {
                mp[k] = v;
            }else{
                mp[k] = min(v,mp[k]);
            }
        }
    }
    ll res = 0;
    for(auto [k,v]:mp){
        if(v<=m){
            res = max(k,res);
        }
    }
    cout<<res<<"\n";

    return 0;
}