#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<long long> tree;
    vector<bool> lazy;
    
    SegmentTree(int n) : n(n) {
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, false);
    }
    
    SegmentTree(vector<long long>& arr) : n(arr.size()) {
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, false);
        build(arr, 1, 0, n - 1);
    }
    
    void build(vector<long long>& arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2*node, l, mid);
        build(arr, 2*node+1, mid+1, r);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    
    void push_down(int node, int l, int r) {
        if (lazy[node]) {
            int mid = (l + r) / 2;
            
            tree[2*node] = 0;
            lazy[2*node] = true;
            
            tree[2*node+1] = 0;
            lazy[2*node+1] = true;
            
            lazy[node] = false;
        }
    }
    
    // ---- Rango: poner en 0 ----
    void updateRangeZero(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return;
        
        if (ql <= l && r <= qr) {
            tree[node] = 0;
            lazy[node] = true;
            return;
        }
        
        push_down(node, l, r);
        
        int mid = (l + r) / 2;
        updateRangeZero(2*node, l, mid, ql, qr);
        updateRangeZero(2*node+1, mid+1, r, ql, qr);
        
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    
    // ---- Rango: consultar suma ----
    long long querySum(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        
        if (ql <= l && r <= qr) {
            return tree[node];
        }
        
        push_down(node, l, r);
        
        int mid = (l + r) / 2;
        long long leftSum = querySum(2*node, l, mid, ql, qr);
        long long rightSum = querySum(2*node+1, mid+1, r, ql, qr);
        
        return leftSum + rightSum;
    }
    
    // ---- Punto: actualizar un solo valor ----
    void updatePoint(int node, int l, int r, int idx, long long val) {
        if (l == r) {
            // llegamos a la hoja que buscamos
            tree[node] = val;
            return;
        }
        
        push_down(node, l, r); // importante: bajar la marca lazy antes de seguir
        
        int mid = (l + r) / 2;
        if (idx <= mid) {
            updatePoint(2*node, l, mid, idx, val);
        } else {
            updatePoint(2*node+1, mid+1, r, idx, val);
        }
        
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    
    // ---- Punto: consultar un solo valor ----
    long long queryPoint(int node, int l, int r, int idx) {
        if (l == r) {
            return tree[node];
        }
        
        push_down(node, l, r); // igual, hay que bajar la marca lazy
        
        int mid = (l + r) / 2;
        if (idx <= mid) {
            return queryPoint(2*node, l, mid, idx);
        } else {
            return queryPoint(2*node+1, mid+1, r, idx);
        }
    }
    
    // ---- Wrappers públicos (índices 0-based) ----
    void setRangeToZero(int l, int r) {
        updateRangeZero(1, 0, n - 1, l, r);
    }
    
    long long rangeSum(int l, int r) {
        return querySum(1, 0, n - 1, l, r);
    }
    
    void updateSingle(int idx, long long val) {
        updatePoint(1, 0, n - 1, idx, val);
    }
    
    long long querySingle(int idx) {
        return queryPoint(1, 0, n - 1, idx);
    }
};

struct UnionFind {
    vector<int> parent;
    vector<int> size;   // tamaño del componente (para unión por tamaño)
    int numComponents;  // cantidad de componentes actuales
    
    UnionFind(int n) {
        parent.resize(n);
        size.assign(n, 1);
        numComponents = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i; // cada nodo es su propio padre al inicio
        }
    }
    
    // Encuentra el representante (raíz) del componente, con compresión de camino
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // compresión de camino
        }
        return parent[x];
    }
    
    // Une los componentes de x e y (unión por tamaño)
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false; // ya estaban en el mismo componente
        
        parent[rootX] = rootY;      // x (su raíz) queda colgado de y (su raíz)
        size[rootY] += size[rootX]; // el tamaño se acumula en la nueva raíz: rootY
        numComponents--;
        
        return true;
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    
    int componentSize(int x) {
        return size[find(x)];
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,q;cin>>n>>q;
    vll arr(n+1);
    arr[0] = 1e18;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i+1];
    }
    
    vll cant(n+1);
    SegmentTree st(cant);
    UnionFind uf(n+1); 
    ll res = 0;
    for (int i = 0; i < q; i++)
    {
        ll c;cin>>c;
        if(c == 1){
            ll b,v;cin>>b>>v;
            if(st.querySingle(b) ==0) uf.parent[b] = b;
            ll p = uf.find(b);
            while(st.querySingle(p)+v>arr[p])
            {
                v = v- arr[p]+st.querySingle(p); 
                st.updateSingle(p,arr[p]);
                if(st.querySingle(p-1) ==0) uf.parent[p-1] = p-1;
                uf.unite(p,p-1);
                p= uf.find(p);
            }
            st.updateSingle(p,st.querySingle(p)+v);
        }else{
            ll l,r;cin>>l>>r;
            res= st.rangeSum(l,r);
            st.setRangeToZero(l,r);
            cout<<res<<"\n";
        }
        // for (int i = 0; i <=n; i++)
        // {
        //     cout<<st.querySingle(i)<<" ";
        // }cout<<"\n";
        
    }
    
    return 0;
}