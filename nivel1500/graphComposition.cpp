#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()



class DisjointSet {
private:
    vll parent;
    vll size; // Usamos tamaño para Union by Size

public:
    // Constructor: Inicializa 'n' elementos de 0 a n-1
    DisjointSet(ll n) {
        parent.resize(n);
        // Inicialmente, cada elemento es su propio padre
        std::iota(parent.begin(), parent.end(), 0); 
        // Inicialmente, cada conjunto tiene tamaño 1
        size.assign(n, 1);
    }

    // Operación Find con Path Compression
    ll find(ll i) {
        if (parent[i] == i)
            return i;
        // Compresión de camino: el padre ahora apunta directamente a la raíz
        return parent[i] = find(parent[i]);
    }

    // Operación Union por Tamaño (Union by Size)
    bool unite(ll i, ll j) {
        ll root_i = find(i);
        ll root_j = find(j);

        // Si ya están en el mismo conjunto, no se hace nada
        if (root_i == root_j) {
            return false; 
        }

        // El conjunto más pequeño se une al más grande
        if (size[root_i] < size[root_j]) {
            parent[root_i] = root_j;
            size[root_j] += size[root_i];
        } else {
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
        }
        return true; // Unión exitosa
    }

    // Función opcional para obtener el tamaño del conjunto de un elemento
    ll getSize(ll i) {
        return size[find(i)];
    }
};

ll dfs(ll x, vector<vll> &gra, vector<ll> &vis, DisjointSet &dsu){
    if(vis[x])return 0;
    vis[x] = 1;
    ll res = 0;
    for(auto ni:gra[x]){
        if(vis[ni])continue;
        if(dsu.find(ni)!=dsu.find(x)){res++;continue;}
        res+=dfs(ni,gra,vis,dsu);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll  n,m,m2;cin>>n>>m>>m2;
        DisjointSet dsu(n);
        vector<vll> F(n);
        vector<vll> G(n);
        for (int i = 0; i < m; i++)
        {
            ll a,b;cin>>a>>b;
            a--,b--;
            F[a].push_back(b);
            F[b].push_back(a);
        }
        for (int i = 0; i < m2; i++)
        {
            ll a,b;cin>>a>>b;
            a--,b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        for (int i = 0; i < n; i++)
        {       
            for(auto x:G[i]){
                dsu.unite(i,x);
            }
        }
        set<ll> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(dsu.find(i));
        }
        vll vis(n);
        ll res = 0;
        for(auto x:st){
            // cout<<x<<"\n";
            res+=dfs(x,F,vis,dsu);
        }
        for (int i = 0; i < n; i++)
        {
            if(vis[i] == 0){
                res++;
                res+= dfs(i,F,vis,dsu);
            }
        }
        cout<<res<<"\n";
    }
    

    return 0;
}