#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()
const ll MOD = 998244353;
const int MAXN = 5e5 + 1000;
vector<ll> fact(MAXN), invFact(MAXN);

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
    for (int i = 1; i < MAXN; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[MAXN - 1] = binpow(fact[MAXN - 1], MOD - 2);

    for (int i = MAXN - 2; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

ll comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invFact[k] % MOD
                   * invFact[n - k] % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    init();
    while(t--){
        vll arr;
        for (int i = 0; i < 26; i++)
        {
            ll a;cin>>a;
            if(a!=0)arr.push_back(a);
        }
        ll m = arr.size();
        ll total = accumulate(all(arr),0LL);
        ll mitad = accumulate(all(arr),0LL)/2;
        vector<ll> vec;
        for (int i = 0; i < 1LL<<m; i++)
        {
            ll temp = i;
            ll sum = 0;
            for (int j = 0; j < m; j++)
            {
                if(temp&1){
                    sum+= arr[j];   
                }
                temp/=2;
            }
            if(sum == mitad){
                vec.push_back(i);
            }
        }
        // cout<<(1<<m)<<"\n";
        ll fn = 0;
        // for(auto x:arr)cout<<x<<" ";cout<<"\n";
        // cout<<vec.size()<<"\n";
        for (int i = 0; i < vec.size(); i++)
        {
            
            ll res = 1;
            ll temp = vec[i];
            // cout<<temp<<"\n";
            ll x = 1,y = 1;
            ll a = mitad,b = total-mitad;
            for (int j = 0; j < m; j++)
            {
                if(temp&1){
                    x = (x * comb(a,arr[j]))%MOD;
                    a-=arr[j];
                }else{
                    y = (y * comb(b,arr[j]))%MOD;
                    b-=arr[j];
                }
                temp/=2;
            }
            res = (((res*  x)%MOD) * y)%MOD;
            fn = (fn+res)%MOD;
        }
        cout<<fn<<"\n";
        
        
    }

    return 0;
}