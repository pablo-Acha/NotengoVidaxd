#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n) { return n * (n + 1) / 2; }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        ll k, n;
        cin >> k >> n;
        if (n & 1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << k << " ";
            }
            cout << "\n";
        }
        else
        {
            ll r = k;
            vll res(n);
            bool f = 0;
            ll p = 0;
            ll ind = 0;
            for (ll i = 31; i >= 0; i--)
            {
                if ((k >> i) & 1)
                {
                    f = 1;
                    for (int j = 0; j < n; j++)
                    {
                        if (ind == j)
                            continue;
                        res[j] += 1LL << i;
                    }
                    ind = min(ind+1,n-1);
                    p = min(p+1,n);
                }
                else if(f && (k>>i))
                {
                    for (int j = 0; j < p-(p&1); j++)
                    {
                        res[j] += 1LL<<i;
                    }
                    
                }
                // cout<<ind<<" "<<i<<"\n";
            }
            for (auto a : res)
                cout << a << " ";
            cout << "\n";
        }
    }
    return 0;
}