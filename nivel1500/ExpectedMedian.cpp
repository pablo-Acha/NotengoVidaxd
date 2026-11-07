#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll MAXN = 2e5 + 5; 

ll fact[MAXN];
ll invFact[MAXN];

ll power(ll base, ll exp)
{
    ll res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n)
{
    return power(n, MOD - 2);
}

void precompute()
{
    fact[0] = 1;
    invFact[0] = 1;

    for (int i = 1; i < MAXN; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);

    for (int i = MAXN - 2; i >= 1; i--)
    {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    ll t;cin>>t;
    while (t--)
    {
        ll n,k;cin>>n>>k;
        ll ceros = 0;
        ll unos = 0;
        vll arr(n);for(auto &a:arr){cin>>a;if(!a)ceros++;else unos++;}
        // if(k == 1){
        //     cout<<unos<<"\n";
        //     continue;
        // }
        ll res= 0;
        sort(all(arr));
        ll m = k/2;
        for (int i = k/2; i < n-(k/2); i++)
        {
            ll M = n-1-i;
            // cout<<i<<"\n";
            if(arr[i] == 1)
            {
                res = ((nCr(i,k/2) * nCr(M,k/2))%MOD + res)%MOD; 
            }
        }
        cout<<res<<"\n";
        
    }
    
    return 0;
}