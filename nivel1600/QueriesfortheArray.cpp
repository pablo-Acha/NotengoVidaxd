
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;
    while (t--) {
        string s; cin >> s;
        ll n = s.size();

        vll rre(n + 10, 0);
        ll ind = 0;
        ll sorted = 0;
        bool f = 1;

        for (int i = 0; i < n; i++) {
            if (s[i] == '+') {
                ind++;
                rre[ind] = rre[ind - 1];

            } else if (s[i] == '-') {
                rre[ind] = 0;
                ind--;
                sorted = min(sorted, ind);

            } else if (s[i] == '1') {
                if (rre[ind] == -1) {
                    f = 0;
                    break;
                }
                sorted = ind;
            }else{
                if (ind <= 1 || ind <= sorted) {
                    f = 0;
                    break;
                }
                rre[ind] = -1;
            }
        }

        cout << (f ? "YES\n" : "NO\n");
    }

    return 0;
}
