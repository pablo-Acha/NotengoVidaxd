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
    vector<vll> dist(n+1,vll(2,1e18));
    vector<vector<pll>> grafo(n+1);
    for (int i = 0; i < m; i++)
    {
        ll a,b,w;cin>>a>>b>>w;
        grafo[a].push_back({w,b});
    }
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>
        ,greater<tuple<ll,ll,ll>>> pq;

    pq.push({0,1,0});
    dist[1][0] = 0;
    while(!pq.empty()){
        auto [d,v,us] = pq.top();
        pq.pop();
        if(d>dist[v][us])continue;
        
        for(auto [w,ni]:grafo[v]){
            if(w+dist[v][us]<dist[ni][us]){
                dist[ni][us]=w+dist[v][us];
                pq.push({dist[v][us]+w,ni,us});
            }
            if(!us && (w/2)+dist[v][0]<dist[ni][1]){
                dist[ni][1]=(w/2)+dist[v][0];
                pq.push({(w/2)+dist[v][0],ni,1});
            }
        }
        
        
    }
    
    cout<<dist[n][1]<<"\n";   
    return 0;
}