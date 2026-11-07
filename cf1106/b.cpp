#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<ll> vll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n;cin>>n;
        vll arr(n+1);
        ll res = 0;
        for (int i = 1; i <= n; i++)
        {
            res+= (n/i)*(n/i);
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     res += arr[i]*arr[i];
        // }
        cout<<res<<"\n";
    }
}