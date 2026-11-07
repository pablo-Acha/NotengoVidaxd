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
    vll primos;
    vll vis(1e5+1000);
    for (ll i = 2; i*i <= 1e10; i++)
    {
        if(vis[i])continue;
        primos.push_back(i);
        for (ll j = i*2; j*j <= 1e10; j+=i)
        {
            vis[j] = 1;
        }
    }

    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        map<ll,vll> mp;
        vll p; 
        for(auto x:primos){
            if(x>n)break;
            p.push_back(x);
        }
        ll m = p.size();
        vll vis(n+1);
        for (ll i = m - 1; i >= 0; i--)
        {
            ll x  = p[i];
            for (ll j = x; j <=n; j+=x)
            {
                if(vis[j])continue;
                vis[j] = 1;
                mp[x].push_back(j);
            }
        }
        vll res(n+1);
        for(auto [k,v]:mp){
            ll z = v.size();
            for (int i = 0; i < z; i++)
            {
                res[v[(i+1)%z]] = v[i];
            }            
        }
        res[1] = 1;
        for (int i =1; i <= n; i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<"\n";
        
    }   
    

    return 0;
}