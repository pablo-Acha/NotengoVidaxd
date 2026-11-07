#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

struct ari {
    ll c;
    ll a;
    ll b;
    ari(ll c, ll a, ll b) : c(c), a(a), b(b) {}
};

bool dfs(int u, vll &color, vector<vll> &g, vll &topo_order) {
    color[u] = 1; 

    for (int v : g[u]) {
        if (color[v] == 1) return true; 
        if (color[v] == 0 && dfs(v, color, g, topo_order)) return true;
    }

    
    color[u] = 2; 
    topo_order.push_back(u);
    return false;
}

bool ciclo(ll n, vector<vll> &grafo, vll &color, vll &topo_order) {
    for (int i = 0; i < n; i++) {
        if (color[i] == 0 && dfs(i, color, grafo, topo_order))
            return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        vector<vll>grafo(n);
        vll val(n);
        vector<ari> aris;
        for (int i = 0; i < m; i++)
        {
            ll c,a,b;cin>>c>>a>>b;            
            a--,b--;
            if(a == b){
                if(c == 2){
                    val[a] = -1;
                }
            }else{
                aris.emplace_back(c,a,b);
            }
        }
        bool f = 1;
        for (int i = 0; i < aris.size(); i++)
        {
            ll a =aris[i].a;
            ll b =aris[i].b;
            ll c =aris[i].c;
            if(val[a]>=0 && val[b]>= 0 || val[a]<0 && val[b]<0){
                if(val[a]>=0 && val[b]>= 0 && c == 2 || val[a]<0 && val[b]<0 && c == 1){
                    f = 0;
                    break;
                }
            }else{
                if(c == 1){
                    if(val[a]>=0){
                        grafo[a].push_back(b);
                    }else{
                        grafo[b].push_back(a);
                    }
                }else{
                    if(val[a]<0){
                        grafo[a].push_back(b);
                    }else{
                        grafo[b].push_back(a);
                    }
                }
            }
        }
        // vector<vector<int>> g(n);
        if(f){
            vll color(n, 0); 
            vll topo_order;
            if(ciclo(n,grafo,color,topo_order)){
                cout<<"NO\n";
            }else{
                cout<<"YES\n";
                reverse(all(topo_order));
                ll magnitud_actual = n; 

                for (int nodo : topo_order) {
                    if (val[nodo] < 0) {
                        val[nodo] = -magnitud_actual;
                    } else {
                        val[nodo] = magnitud_actual;
                    }
                    magnitud_actual--;
                }
                for(auto x:val){
                    cout<<x<<" ";
                }
                cout<<"\n";
            
            }
        }else{
            cout<<"NO\n";
        
        }

        
        // vll arr(n);for(auto &a:arr)cin>>a;
    
    }

    return 0;
}