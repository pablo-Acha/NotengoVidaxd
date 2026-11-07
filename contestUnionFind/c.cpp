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

        // if (tam[a] < tam[b]) swap(a, b);

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll q;cin>>q;
    ll n = 1LL<<20;
    vll val(n,-1);
    DSU ds(n);    
    for (int i = 0; i < q; i++)
    {
        ll t;cin>>t;
        ll x;cin>>x;
        if(t == 1){
            if(ds.find(x%n) == x%n){
                val[x%n]= x;
                ds.unite((x+1)%n,x%n);
            }else{
                val[ds.find(x%n)]= x;
                ds.unite((ds.find(x%n)+1)%n,ds.find(x%n));
            }
        }else{
            cout<<val[x%n]<<"\n";
        }
    }
    
    return 0;
}