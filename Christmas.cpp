#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
const long long MOD = 998244353 ;
ll permuta(ll n){
    ll res = 1;
    for (int i = 1; i <= n; i++)
    {
        res = (res*i)%MOD;
    }
    return res;
}
long long modpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

long long modinv(long long a) {
    return modpow(a, MOD - 2); // Fermat
}

long long combinacion(int n, int r) {
    if (r > n) return 0;
    if (r > n - r) r = n - r;

    long long res = 1;
    for (int i = 0; i < r; i++) {
        res = res * (n - i) % MOD;
        res = res * modpow(i + 1, MOD - 2) % MOD;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vll arr(n+1);for(auto &a:arr)cin>>a;
        ll mx = 0, altos = 0,bajos = 0;
        ll sum = accumulate(arr.begin(),arr.end(),0);
        ll mxmx = sum/n + (sum%n>0);
        altos  = sum%n;
        bajos = n-altos;
        for (int i = 1; i <= n; i++)
        {
            mx+= arr[i] == mxmx;
        }
        ll comb = combinacion(n-mx,altos-mx);
        ll perm1 = permuta(altos);
        ll perm2 = permuta(bajos);
        ll res = (((comb* perm1)%MOD) * perm2) %MOD;
        cout<<mx<<" "<<altos<<" "<<bajos<<" "<<mxmx<<" "<<comb<<" "<<perm1<<" "<<perm2<<" "<<sum<<"\n";
        cout<<res<<"\n";
        
        
    }
    return 0;
}