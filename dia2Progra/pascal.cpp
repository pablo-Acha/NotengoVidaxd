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

    ll n;cin>>n;
    ll MOD  = 1e9+7;
    vector<vector<int>> C(n + 1, vector<int>(n + 1));

for (int i = 0; i <= n; i++) {
    C[i][0] = C[i][i] = 1 % MOD;
    for (int j = 1; j < i; j++) {
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
}
for(auto v:C){
    for(auto a:v){
        cout<<a<<" ";
    }
    cout<<"\n";
}


    return 0;
}