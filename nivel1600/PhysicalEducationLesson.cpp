#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;

    while(t--) {
        ll n, x;
        cin >> n >> x;

        set<ll> st;

        auto solve = [&](ll aux) {
            if(aux <= 0 || aux % 2 != 0) return;

            ll m = aux / 2;

            for(ll i = 1; i <= m / i; i++) {
                if(m % i != 0) continue;

                ll k1 = m / i + 1;
                ll k2 = i + 1;

                if(k1 >= x) st.insert(k1);
                if(k2 >= x) st.insert(k2);
            }
        };

        solve(n - x);
        solve(n + x - 2);

        cout << st.size() << "\n";
    }

    return 0;
}