#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
// typedef  pair<ll,ll> pii;
typedef  pair<ll,ll> pll;
// typedef  vector<ll> vi;

#define all(x) (x).begin(), (x).end()
struct FenwickTree {
    ll size;
    vector<ll> tree;

    FenwickTree(ll n) : size(n), tree(n + 1, 0) {}

    void add(ll idx, ll val) {
        for (; idx <= size; idx += idx & -idx) {
            tree[idx] += val;
        }
    }

    ll query(ll idx) {
        ll sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }
};
vector<ll> menoresALaDerecha(const vector<ll>& arr) {
    ll n = arr.size();
    vector<ll> resultado(n, 0);
    if (n == 0) return resultado;

    vector<ll> temp = arr;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    FenwickTree bit(temp.size());

    for (ll i = n - 1; i >= 0; --i) {
        ll pos = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin() + 1;

        resultado[i] = bit.query(pos - 1);

        bit.add(pos, 1);
    }

    return resultado;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        vector<pll> aux(n);
        for (ll i = 0; i < n; i++)
        {
            auto &[b,a] = aux[i];
            cin>>a>>b;
        }
        
        sort(all(aux));
        vll arr(n);
        for (ll i = 0; i < n; i++)
        {
            arr[i]= aux[i].second;
        }
        vll temp = menoresALaDerecha(arr);
        ll res = accumulate(all(temp),0LL);
        cout<<res<<"\n"; 
    }
    

    return 0;
}