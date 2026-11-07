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

    int H, M, S; cin >> H >> M >> S;
    int total = H * 3600 + M * 60 + S;
    if (total < 9000) cout << "-\n";
    else if (total > 9000) cout << "+\n";
    else cout << "=\n";

    return 0;
}