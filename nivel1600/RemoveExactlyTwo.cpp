#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

void dfs(ll x,ll p,vll &vis,vector<vll> &arbol,set<ll> &borrados){
    if(vis[x])return;
    vis[x] = 1;
    for(auto ni:arbol[x]){
        if(ni == p || vis[ni] || borrados.find(ni) != borrados.end())continue;
        dfs(ni,x,vis,arbol,borrados);
    }
}

void dfs1(vector<vll> &g, ll u, ll p, ll &nodo){
    if(g[u].size() >= g[nodo].size()) nodo = u;  
    for(auto v : g[u]) {
        if(v == p) continue;  
        dfs1(g, v, u, nodo); 
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<vll> arbol(n);
        vll grado(n);
        vector<pll> orden;
        set<ll> borrados; 
        for (int i = 0; i < n-1; i++)
        {
            ll a,b;cin>>a>>b;
            a--,b--;
            arbol[a].push_back(b);
            arbol[b].push_back(a);
            grado[a]++;
            grado[b]++;
        }

        ll nodo = 0;
        dfs1(arbol,0,0,nodo);
        borrados.insert(nodo);
        for (int i = 0; i < n; i++)
        {
            if(borrados.find(i) !=borrados.end())continue;
            for(auto x:arbol[i])
            {
                if(x == nodo){
                    grado[i]--;
                    break;
                }
            }
            orden.push_back({grado[i],i});
        }
        // for (int i = 0; i < n; i++)
        // {
        //     if(nodo == i)continue;
        //     orden.push_back({grado[i],i});
        // }
        sort(all(orden));
        ll mx = orden[orden.size()-1].second;
        borrados.insert(mx);
        // orden.resize(0);
        for (int i = 0; i < n; i++)
        {
            if(borrados.find(i) !=borrados.end())continue;
            for(auto x:arbol[i])
            {
                if(x == mx){
                    grado[i]--;
                    break;
                }
            }
            // orden.push_back({grado[i],i});
        }
        
        // sort(all(orden));
        ll res = 0;
        vll vis(n);
        for (int i = 0; i < n; i++)
        {
            if(borrados.find(i) !=borrados.end() || vis[i])continue;
            dfs(i,0,vis,arbol,borrados);
            res++;
        }
        cout<<res<<"\n";
        
        
    }

    return 0;
}