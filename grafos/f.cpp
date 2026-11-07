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
    vector<vector<pll>> grafo(n+1);
    vll dist(n+1,1e18);
    
    for (int i = 0; i < m; i++)
    {
        ll a, b,w;cin>>a>>b>>w;
        grafo[a].push_back({w,b});
    }
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto [d,x] = pq.top();
        pq.pop();
        if(d>dist[x])continue;
        dist[x] = d;
        for(auto [w,ni]:grafo[x]){
            if(w+dist[x]>=dist[ni])continue;
            pq.push({w+dist[x],ni});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<"\n";
    
    return 0;
}