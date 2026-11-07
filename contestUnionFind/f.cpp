#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()
struct DSU {
    vll parent, tam,L,R;
    ll comp, mx;

    DSU(ll n) : parent(n), tam(n, 1), comp(n), mx(n > 0 ? 1 : 0) {
        iota(all(parent), 0LL);
        L = parent;
        R = parent;
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
        L[a] = min(L[a],L[b]);
        R[a] = max(R[a],R[b]);
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

    ll n,q;cin>>n>>q;
    DSU dsu(n);
    vll color(n);
    vll tamanio(n,1);
    iota(all(color),0LL);
    // for(auto x:color)cout<<x<<" ";cout<<"\n";
    for (int i = 0; i < q; i++)
    {
        ll t;cin>>t;
        if(t == 1){
            ll x,c;cin>>x>>c;
            x--,c--;
            tamanio[color[dsu.find(x)]]-=dsu.size(dsu.find(x));
            color[dsu.find(x)] = c;
            tamanio[c]+=dsu.size(dsu.find(x));
            ll l = dsu.L[dsu.find(x)]-1,r = dsu.R[dsu.find(x)]+1;
            if(l>=0 && color[dsu.find(l)] == color[dsu.find(x)]){
                dsu.unite(l,x);
            }
            if(r<n && color[dsu.find(r)] == color[dsu.find(x)]){
                dsu.unite(r,x);
            }
            // for (int i = 0; i < n; i++)
            // {
            //     cout<<color[dsu.find(i)]<<" ";
            // }
            // cout<<"\n";
            
            // for(auto r:tamanio)cout<<r<<" ";cout<<"\n";
        }else{
            ll c;cin>>c;c--;
            cout<<tamanio[c]<<"\n";
        }
    }
    

    return 0;
}