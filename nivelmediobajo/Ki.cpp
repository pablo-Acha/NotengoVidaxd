#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,q;cin>>n>>q;
    vector<vll> graf(n+1);
    for (ll i = 0,a,b; i < n-1; i++)
    {
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    vll val(n+1);
    for (ll i = 0,a,b; i < q; i++)
    {
        cin>>a>>b;
        val[a] += b;
    }
    vll vis(n+1);
    queue<ll> qu;
    qu.push(1);
    vis[1] = 1;
    while(!qu.empty()){
        auto a = qu.front();
        qu.pop();
        for(auto ni:graf[a]){
            if(vis[ni])continue;
            vis[ni] = 1;
            val[ni]+=val[a];
            qu.push(ni);
        }
    }
    for (int i =1; i <= n; i++)
    {
        cout<<val[i]<<" ";
    }
    cout<<"\n";
    return 0;
}