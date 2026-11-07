#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()
const ll MOD = 10007; 
long long comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    ll aux = n-k;
    if(k>=aux){
        ll up = 1;
        ll down = 1;
        for (int i = k+1; i <= n; i++)
        {
            up = (up *i) %MOD;
        }
        for (int i = 1; i <= aux; i++)
        {
            down = (down *i) %MOD;        
        }
         
    }else{

    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, k, n,  m; cin>>a>>b>>k>>n>>m;
    ll res = ((comb(k,n) * power(b,m))%MOD * power(a,n))%MOD;

    return 0;
}