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

    ll n,q;cin>>n>>q;
    ll m = 7e5;
    DSU dsu(m);
    vll arr(n);
    iota(all(arr),0LL);
    map<ll,ll> mp;
    for (int i = 0; i < n; i++)
    {
        mp[i] = i;
    }
    ll last = n;
    for (int i = 0; i < q; i++)
    {
        ll t;cin>>t;
        if(t == 1){
            ll x,y;cin>>x>>y;
            x--,y--;
            if(arr[x]!=-1 && arr[y]!=-1){
                ll a = dsu.find(arr[x]);
                ll b = dsu.find(arr[y]);
                mp.erase(b);
                mp.erase(a);
                dsu.unite(a,b);
                
                arr[y] = -1;
                arr[x] = dsu.find(b);
                // cout<<i<<" "<<dsu.find(b)<<" "<<b<<"\n";
                mp[dsu.find(b)] = x;
            }else if(arr[y] != -1){
                arr[x] = arr[y];
                arr[y] = -1;
                mp[arr[x]] = x;
            }
        }else if(t == 2){
            ll x;cin>>x;
            x--;
            if(arr[x] == -1){
                arr[x] = last;
                mp[last] = x;
            }else{
                dsu.unite(last,arr[x]);
                mp.erase(arr[x]);
                arr[x] = dsu.find(last);
                mp[arr[x]] =x; 
            }
            last++;
        }else{
            ll x;cin>>x;
            x--;
            x = dsu.find(x);
            // cout<<x<<"\n";
            cout<<mp[x]+1<<"\n";
        }
        // for (int i = 0; i < last; i++)
        // {
        //     cout<<dsu.find(i)<<" ";
        // }
        // cout<<"\n";
        // for (int i = 0; i < last; i++)
        // {
        //     cout<<mp[dsu.find(i)]<<" ";
        // }
        // cout<<"\n-----------------\n";
    }
    
    return 0;
}