#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> ans(n, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {

            int d1 = abs(i - j);
            int d2 = abs(i - x) + 1 + abs(y - j);
            int d3 = abs(i - y) + 1 + abs(x - j);

            int d = min({d1, d2, d3});
            ans[d]++;
        }
    }

    for (int k = 1; k <= n - 1; k++) {
        cout << ans[k] << "\n";
    }
}