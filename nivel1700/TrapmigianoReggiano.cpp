#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

void dfs(ll x,vll& vis, vector<vll>& grafo){
    for(auto ni:grafo[x]){
        if(vis[ni] == -1){
            vis[ni] = vis[x]+1;
            dfs(ni,vis,grafo);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,st,fn;cin>>n>>st>>fn;
        st--,fn--;
        vector<vll> grafo(n); 
        for (int i = 0; i < n-1; i++)
        {
            ll a,b;cin>>a>>b;
            a--,b--;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }
        vll vis(n,-1);
        vis[fn] = 0;
        dfs(fn,vis,grafo);
        priority_queue<pll> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push({vis[i],i});
        }
        while(!pq.empty()){
            auto [p,ind]= pq.top();
            pq.pop();
            cout<<ind+1<<" "; 
        }
        cout<<"\n";
        
    }
    

    return 0;
}