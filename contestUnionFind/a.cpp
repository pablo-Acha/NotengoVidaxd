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


ll ind(ll n, vll &aux){
    return lower_bound(all(aux),n)-aux.begin();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;cin>>n;
    vll arr(n);for(auto &x:arr)cin>>x;
    vll aux= arr;
    sort(all(aux));
    aux.erase(unique(all(aux)),aux.end());
    ll m = aux.size();
    DSU ds(m);
    ll l = 0,r = n-1;
    ll total = m;
    // for(auto r:aux)cout<<r<<" ";cout<<"\n";
    while(l<r){
        ll x = ind(arr[l],aux);
        ll y = ind(arr[r],aux);
        // cout<<x<<" "<<y<<"\n";
        if(!ds.same(x,y)){
            // cout<<"-------"<<"\n";
            ds.unite(x,y);
        }
        l++,r--;
    }
    ll res= m-ds.comp;
    cout<<res<<"\n";
    return 0;
}