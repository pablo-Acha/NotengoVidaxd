#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];

    map<ll,ll> last;
    ll ini = 0, mx = 0;

    for (ll i = 0; i < n; i++) {
        if (last.count(arr[i]) && last[arr[i]] >= ini) {
            ini = last[arr[i]] + 1; // 🔥 clave
        }
        last[arr[i]] = i;
        mx = max(mx, i - ini + 1);
    }

    cout << mx << "\n";
}