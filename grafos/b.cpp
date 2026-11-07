#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

bool dfs(ll inicio, vector<vll>& grafo,
         vll& topo, vll& vis) {

    stack<pair<ll,ll>> st;

    st.push({inicio, 0});
    vis[inicio] = 1;

    while (!st.empty()) {

        auto &[u, i] = st.top();

        if (i == grafo[u].size()) {
            vis[u] = 2;
            topo.push_back(u);
            st.pop();
            // El vértice u terminó.
            // Completa las tres operaciones.
        }
        else {
            ll v = grafo[u][i];
            i++;
            if(vis[v]== 0){
                st.push({v,0});
            }else if(vis[v] == 1){
                return false;
            }else{
                st.pop();
                st.push({u,i});
            }
            // Caso 1: v está blanco
            // Caso 2: v está gris
            // Caso 3: v está negro
        }
    }

    return true;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;cin>>n>>m;
    vector<vll> grafo(n+1);
    for (int i = 0; i < m; i++)
    {
        ll a,b;cin>>a>>b;
        grafo[a].push_back(b);
    }    
    vll vis(n+1);
    vll topo;
    bool f = 1;
    for (int i = 1; i <=n; i++)
    {
        if(!vis[i]){
            vis[i]= 1;
            f= dfs(i,grafo,topo,vis);
            if(!f)break;
        }
    }
    if(!f)cout<<"IMPOSSIBLE\n";
    else {reverse(all(topo));for(auto x:topo)cout<<x<<" ";cout<<"\n";}
    return 0;
}