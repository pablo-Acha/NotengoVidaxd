#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5; // Ajusta según el valor máximo de N que necesites

long long fact[MAXN];
long long invFact[MAXN];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll pares = n/2;
        ll impares = (n+1)/2;
        ll res = ((nCr(impares,2) * pares)%MOD + (nCr(pares,3))%MOD)%MOD;
        cout<<res<<"\n";
    }
    

    return 0;
}