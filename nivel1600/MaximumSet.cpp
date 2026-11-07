#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()
const ll MOD = 998244353;
const int MAXN = 200005;

ll fact[MAXN], invfact[MAXN];

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    fact[0] = 1;

    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invfact[MAXN - 1] = binpow(fact[MAXN - 1], MOD - 2);

    for (int i = MAXN - 2; i >= 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }
}

ll comb(int n, int k) {
    if (k < 0 || k > n) return 0;

    return fact[n] * invfact[k] % MOD
                   * invfact[n - k] % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    ll t;cin>>t;
    while(t--){
        ll l,r;cin>>l>>r;
        ll mx = 0, act= 1;
        while(l*act*2<=r){
            act*=2;
            mx++;
        }
        ll res = 0;
        for (int i = 0; i <= mx; i++)
        {
            if(act*l>r)break;
            ll left = l,right = r,mid = 0;
            while (left<=right)
            {
                mid = (left+right)/2;
                if(mid*act<=r){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
            if(right>=l){
                res = ((comb(mx,i)*(right-l+1))%MOD + res)%MOD;
                // cout<<res<<"\n";
            }   
            act = act/2 * 3;
        }
        cout<<mx+1<<" "<<res<<"\n";

    }

    return 0;
}