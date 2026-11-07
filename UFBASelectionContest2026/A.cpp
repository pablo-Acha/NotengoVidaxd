#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vll a(n);
    for (ll &e: a) cin >> e;

    ll tamanio = 0, sum = 0, blocks = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            sum += a[i];
            tamanio++;
        } else {
            if (tamanio > 1) {
                ll m = tamanio / 2;
                if (tamanio % 2 == 0) {
                    blocks += (4 * m);
                } else {
                    blocks += (4 * (m - 1));
                    blocks += 9;
                }
            }
            tamanio = 0;
        }
    }
    if (tamanio > 1) {
        ll m = tamanio / 2;
        if (tamanio % 2 == 0) {
            blocks += (4 * m);
        } else {
            blocks += (4 * (m - 1));
            blocks += 9;
        }
    }

    ll res = sum - blocks;

    cout << res;

    return 0;
}