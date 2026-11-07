#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define all(x) (x).begin(), (x).end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, q;
        cin >> n >> m >> q;
        vll arr(n);
        for (auto &a : arr)cin >> a;
        vll brr(m);
        for (auto &a : brr)cin >> a;
        sort(all(arr), greater<ll>());
        sort(all(brr), greater<ll>());
        vll aw(n + 1), bw(m + 1);
        for (int i = 1; i <= n; i++)
        {
            aw[i] = arr[i - 1] + aw[i - 1];
        }
        for (int i = 1; i <= m; i++)
        {
            bw[i] = brr[i - 1] + bw[i - 1];
        }
        for (int i = 0; i < q; i++)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            ll b = min(z, y), a = z - b;
            ll l = 0, r = min(x - a, b);
            auto eval = [&](ll k) -> ll
            {
                return aw[k + a] + bw[b - k];
            };

            while (r - l >= 3)
            {
                ll m1 = l + (r - l) / 3;
                ll m2 = r - (r - l) / 3;

                if (eval(m1) < eval(m2))
                {
                    l = m1;
                }
                else
                {
                    r = m2;
                }
            }

            ll res = eval(l);
            ll opt_k = l;
            for (ll k = l + 1; k <= r; k++)
            {
                ll val = eval(k);
                if (val > res)
                { 
                    res = val;
                    opt_k = k;
                }
            }

            cout << res << "\n";
        }
    }

    return 0;
}