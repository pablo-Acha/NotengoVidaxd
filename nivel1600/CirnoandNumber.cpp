
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

#define all(x) (x).begin(), (x).end()

bool backtrack1(int p, vll &dig, deque<ll> &arr, vll &res, bool si) {
    if(p == (int)arr.size()) return true;

    if(!si) {
        res.push_back(dig[0]);
        return backtrack1(p+1, dig, arr, res, false);
    }

    ll pos = lower_bound(all(dig), arr[p]) - dig.begin();

    for(int i = pos; i < (int)dig.size(); i++) {
        res.push_back(dig[i]);

        if(backtrack1(p+1, dig, arr, res, dig[i] == arr[p]))
            return true;

        res.pop_back();
    }

    return false;
}

bool backtrack2(int p, vll &dig, deque<ll> &arr, vll &res, bool si) {
    if(p == (int)arr.size()) return true;

    if(!si) {
        res.push_back(dig.back());
        return backtrack2(p+1, dig, arr, res, false);
    }

    int pos = upper_bound(all(dig), arr[p]) - dig.begin() - 1;

    for(int i = pos; i >= 0; i--) {
        res.push_back(dig[i]);

        if(backtrack2(p+1, dig, arr, res, dig[i] == arr[p]))
            return true;

        res.pop_back();
    }

    return false;
}

ll f(vll &arr) {
    ll x = 0;
    for(auto d : arr) x = x * 10 + d;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--) {
        ll a, n;
        cin >> a >> n;

        vll dig(n);
        for(auto &x : dig) cin >> x;

        sort(all(dig));
        dig.erase(unique(all(dig)), dig.end());

        deque<ll> arr;
        ll temp = a;

        do {
            arr.push_front(temp % 10);
            temp /= 10;
        } while(temp);

        vll res1, res2;
        deque<ll> aux = arr;

        bool existe1 = false;

        if(backtrack1(0, dig, aux, res1, true)) {
            existe1 = true;
        } else {
            res1.clear();

            auto it = upper_bound(all(dig), 0LL);

            if(it != dig.end()) {
                res1.push_back(*it);

                for(int i = 0; i < (int)arr.size(); i++)
                    res1.push_back(dig[0]);

                existe1 = true;
            }
        }

        aux = arr;
        bool existe2 = backtrack2(0, dig, aux, res2, true);

        if(!existe2) {
            res2.clear();

            // Intentar con una cifra menos
            if(arr.size() > 1) {
                for(int i = 0; i + 1 < (int)arr.size(); i++)
                    res2.push_back(dig.back());

                existe2 = true;
            } else if(dig[0] == 0) {
                res2.push_back(0);
                existe2 = true;
            }
        }

        ll ans = LLONG_MAX;

        if(existe1) {
            ll c = f(res1);
            ans = min(ans, abs(a-c));
        }

        if(existe2) {
            ll d = f(res2);
            ans = min(ans, abs(a-d));
        }

        cout << ans << '\n';
    }

    return 0;
}
