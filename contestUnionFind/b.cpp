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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;cin>>n;
    vll arr(n);for(auto &a:arr)cin>>a;
    vll brr(n);for(auto &a:brr)cin>>a;
    vll vis(n);
    ll mx = 0;
    reverse(all(brr));
    vll res;
    DSU ds(n);
    vll val = arr;
    for (int i = 0; i < n; i++)
    {
        res.push_back(mx);
        brr[i]--;
        vis[brr[i]] = 1;
        mx = max(mx,val[brr[i]]);
        if(brr[i]-1>=0 &&vis[brr[i]-1]){
            ll temp = val[ds.find(brr[i]-1)];
            ll temp2 = val[ds.find(brr[i])];
            ds.unite(ds.find(brr[i]-1),ds.find(brr[i]));
            val[ds.find(brr[i])] = temp+temp2;
            mx = max(mx,val[ds.find(brr[i])]);
        }
        if(brr[i]+1<n && vis[brr[i]+1]){
            ll temp = val[ds.find(brr[i]+1)];
            ll temp2 = val[ds.find(brr[i])];
            ds.unite(brr[i]+1,brr[i]);
            val[ds.find(brr[i])] = temp+temp2;
            mx = max(mx,val[ds.find(brr[i])]);
        }
    }
    reverse(all(res));
    for(auto x:res)cout<<x<<"\n";    

    return 0;
}