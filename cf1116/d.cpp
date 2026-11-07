#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()


const int MOD = 998244353;

long long potenciaMod(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long inversoMod(long long n) {
    return potenciaMod(n, MOD - 2);
}

long long calcularSumaProductosMod(int n, int k) {
    if (k <= 0 || n < k) return 0;

    long long N = n + k - 1;
    long long K = 2 * k - 1;

    if (K > N) return 0;

    long long numerador = 1;
    long long denominador = 1;

    for (int i = 1; i <= K; ++i) {
        numerador = (numerador * ((N - i + 1) % MOD)) % MOD;
        denominador = (denominador * i) % MOD;
    }

    return (numerador * inversoMod(denominador)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        string s;cin>>s;
        ll unos = 0;ll ceros = 0;
        for (int i = 0; i < n; i++)
        {
            unos += s[i] == '1';
            ceros += s[i] == '0';
        }
        ll cnt = 0;
        ll aux = 0;
        bool f = 0;
        for (int i = 0; i < n; )
        {
            if(s[i] == '1'){
                aux = 0;
                while(i<n  && s[i] == '1'){
                    aux++;
                    i++;
                }
            }else{
                if(aux>0 && f)cnt++;
                i++;
                f = 1;
            }
        }
        ll k = ceros - 1;
        // cout<<k<<" "<<cnt<<"\n";
        ll res  = calcularSumaProductosMod(k,cnt)-cnt+1;
        cnt = 0;
        aux = 0;
        f = 0;
        for (int i = 0; i < n; )
        {
            if(s[i] == '0'){
                aux = 0;
                while(i<n  && s[i] == '0'){
                    aux++;
                    i++;
                }
            }else{
                if(aux>0&& f)cnt++;
                i++;
                f = 1;
            }
        }
        k = unos - 1;
        // cout<<k<<" "<<cnt<<"\n";
        // cout<<res<<"\n";

        res  += calcularSumaProductosMod(k,cnt)-cnt+1;
        cout<<res<<"\n";
    }

    return 0;
}