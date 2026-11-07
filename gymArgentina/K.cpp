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

    map<int, int> d;
    d[0] = 0;
    d[2] = 1;
    d[4] = 2;
    d[6] = 3;
    d[8] = 4;
    d[1] = 5;
    d[3] = 6;
    d[5] = 7;
    d[7] = 8;

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        cout << d[c] << ' ';
    }
    

    return 0;
}