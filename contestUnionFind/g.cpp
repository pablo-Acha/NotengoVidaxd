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
    vector<map<ll,ll>> mp;
    DSU(ll n) : parent(n), tam(n, 1), comp(n), mp(n),mx(n > 0 ? 1 : 0) {
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
        for(auto [k,v]:mp[b]){
            mp[a][k]+= v;
        }
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
    vll arr(n);for(auto &a:arr)cin>>a;
    DSU ds(n);
    for (int i = 0; i < n; i++)
    {
        ds.mp[i][arr[i]]++;
    }
    
    for (int i = 0; i < q; i++)
    {
        ll t; cin>>t; 
        if(t == 2){
            ll x,y;cin>>x>>y;
            x--;
            x = ds.find(x);
            cout<<ds.mp[x][y]<<"\n";
        }else{
            ll a,b;cin>>a>>b;
            a--,b--;
            if(!ds.same(a,b)){
                ds.unite(a,b);
            }       
            
        }
    }
    
    

    return 0;
}