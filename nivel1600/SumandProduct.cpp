
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll isqrt(ll n) {
    if (n <= 0) return 0;

    ll l = 1, r = min(n, 3037000499LL);
    ll ans = 0;

    while (l <= r) {
        ll mid = l + (r-l)/2;

        if (mid <= n/mid) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    return ans;
}

bool fun(ll x, ll y, ll &a, ll &b) {
    ll D = x*x - 4*y;

    if (D < 0) return false;

    ll raiz = isqrt(D);

    if ((__int128)raiz*raiz != D)
        return false;

    if ((x-raiz)%2 != 0)
        return false;

    a = (x-raiz)/2;
    b = (x+raiz)/2;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;

    while (t--) {
        ll n; cin >> n;

        map<ll,ll> mp;

        for (int i = 0; i < n; i++) {
            ll a; cin >> a;
            mp[a]++;
        }

        ll q; cin >> q;

        while (q--) {
            ll x,y; cin >> x >> y;

            ll a,b;
            ll res = 0;

            if (fun(x,y,a,b)) {
                if (a == b) {
                    res = mp[a]*(mp[a]-1)/2;
                } else {
                    res = mp[a]*mp[b];
                }
            }

            cout << res << " ";
        }

        cout << "\n";
    }
}
