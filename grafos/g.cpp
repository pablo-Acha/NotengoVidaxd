#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()
vll dijstra(ll ini,vector<vector<pll>>& grafo){
    ll n= grafo.size();
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,ini});
    vll dist(n,1e18);
    while(!pq.empty()){
        auto [d,x]= pq.top();
        pq.pop();
        if(d>=dist[x])continue;
        dist[x] = d;
        for(auto [w,ni]:grafo[x]){
            if(w+dist[x]>=dist[ni])continue;
            pq.push({w+dist[x],ni});
        }
    }
    return dist;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;cin>>n>>m;
    vector<vector<pll>> grafo(n+1); 
    vector<vector<pll>> grafo2(n+1); 
    for (int i = 0; i < m; i++)
    {
        ll a,b,w;cin>>a>>b>>w;
        grafo[a].push_back({w,b});
        grafo2[b].push_back({w,a});
    }
    vll arr = dijstra(1,grafo);
    vll brr = dijstra(n,grafo2);
    ll mn= 1e18;
    // for(auto x:arr)cout<<x<<" ";cout<<"\n";
    // for(auto x:brr)cout<<x<<" ";cout<<"\n";
    for (int i = 1; i <= n; i++)
    {
        for(auto [w,u]:grafo[i]){
            ll aux= arr[i]+brr[u]+(w/2);
            mn = min(aux,mn);
        }
        
    }

    cout<<mn<<"\n";
    return 0;
}