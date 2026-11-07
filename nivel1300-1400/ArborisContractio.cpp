#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<vll> grafo(n);
        for (int i = 0; i < n-1; i++)
        {
            ll a,b;cin>>a>>b;
            a--,b--;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }
        if(n == 2){
            cout<<0<<"\n";
            continue;
        }
        ll cnt = 0;
        map<ll,ll> mp;
        for (int i = 0; i < n; i++)
        {
            if(grafo[i].size() == 1){
                cnt++;
                mp[grafo[i][0]]++;
            }
        }
        ll mx = 0;
        for(auto [a,v]:mp){
            mx = max(mx,v);
        }
        // cout<<mx<<"\n";
        cout<<cnt-mx<<"\n";
    }
    return 0;
}