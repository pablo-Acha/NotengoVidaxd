#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;

long long ceil_div(long long a, long long b) {
    // b > 0
    if (a >= 0) return (a + b - 1) / b;
    return a / b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int K;
    cin >> N >> K;

    int L = (int)min<long long>(N, K);

    vector<long long> dp(K + 1, 1), ndp(K + 1);

    if (L == 1) {
        cout << K % MOD << '\n';
        return 0;
    }

    for (int i = 2; i <= L; i++) {
        vector<long long> pref(K + 1, 0);
        for (int v = 1; v <= K; v++) {
            pref[v] = (pref[v - 1] + dp[v]) % MOD;
        }

        fill(ndp.begin(), ndp.end(), 0);

        for (int y = 1; y <= K; y++) {
            long long left  = ceil_div(1LL * i * y - K, i - 1);
            long long right = (1LL * i * y - 1) / (i - 1);

            left = max<long long>(left, 1);
            right = min<long long>(right, K);

            if (left <= right) {
                long long val = pref[right] - pref[left - 1];
                if (val < 0) val += MOD;
                ndp[y] = val;
            }
        }

        dp.swap(ndp);
    }

    long long ans = 0;
    for (int v = 1; v <= K; v++) {
        ans += dp[v];
        if (ans >= MOD) ans -= MOD;
    }

    cout << ans % MOD << '\n';
    return 0;
}