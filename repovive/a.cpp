
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

#define all(x) (x).begin(), (x).end()

struct Fenwick {
    ll n;
    vll bit;

    Fenwick(ll n) : n(n), bit(n+1,0) {}

    void add(ll i, ll val) {
        while(i <= n) {
            bit[i] += val;
            i += i & -i;
        }
    }

    ll query(ll i) {
        ll res = 0;
        while(i > 0) {
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        Fenwick cnt(n),sum(n);
        ll ans = 0;
        ll total = 0;

        for(int i = 1; i <= n; i++){
            ll x;cin>>x;

            ll cant = (i-1)-cnt.query(x);
            ll suma = total-sum.query(x);

            ans += cant*i-suma;

            cnt.add(x,1);
            sum.add(x,i);
            total += i;
        }

        cout<<ans<<'\n';
    }

    return 0;
}
