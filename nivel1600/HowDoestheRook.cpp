#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

const ll MOD = 1e9+7;

ll pa(ll n){
    return (n*(n-1))/2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){

        ll n,m;cin>>n>>m;
        ll M = n;
        for (int i = 0; i < m; i++)
        {
            ll a,b;cin>>a>>b;
            if(a == b)M--;
            else M-=2;
        }
        ll a = 1, b = 1;

        for (ll i = 2; i <= M; i++) {
            ll c = (b + 2 * (i - 1) % MOD * a % MOD) % MOD;
            a = b;
            b = c;
        }
        cout << b << '\n';
    }
        

    return 0;
}