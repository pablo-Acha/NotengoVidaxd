#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

struct DSU {
    vll parent, tam;
    ll comp, mx;

    DSU(ll n) : parent(n), tam(n, 1), comp(n), mx(n > 0 ? 1 : 0) {
        iota(all(parent), 0LL);
    }

    ll find(ll x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(ll a, ll b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (tam[a] < tam[b]) swap(a, b);

        parent[b] = a;
        tam[a] += tam[b];

        comp--;
        mx = max(mx, tam[a]);

        return true;
    }

    bool same(ll a, ll b) {
        return find(a) == find(b);
    }

    ll size(ll x) {
        return tam[find(x)];
    }
};

struct nodo{
    ll a,b,c;
    bool operator<(const nodo& otro) const {
        if (c != otro.c) return c > otro.c;
        if (a != otro.a) return a > otro.a;
        return b > otro.b;
    }
    bool operator>(const nodo& otro) const
    {
        if(c != otro.c) return c<otro.c;
        if(a != otro.a) return a<otro.a;
        return b < otro.b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;cin>>n>>m;
    DSU ds(n);
    if(m<n-1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    priority_queue<nodo> pq;
    for (int i = 0; i < m; i++)
    {
        nodo x;
        cin>>x.a>>x.b>>x.c;
        x.a--,x.b--;
        pq.push(x);
    }
    
    ll cnt = 0;
    ll res = 0;
    while(!pq.empty()){
        nodo x = pq.top();
        pq.pop();
        // cout<<x.a<<" "<<x.b<<"\n";
        if(ds.find(x.a) == ds.find(x.b))continue;
        ds.unite(x.a,x.b);
        cnt++;
        res+= x.c;
        if(cnt == n-1)break;
    }
    if(ds.comp!=1){
        cout<<"IMPOSSIBLE\n";
    }else{
        cout<<res<<"\n";
    }
    

    return 0;
}