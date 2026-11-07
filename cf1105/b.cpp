#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
const long long p = MOD - 1;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    if (base < 0) base += mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n, m, r, c;
        cin >> n >> m >> r >> c;
        
        long long nm = ((n % p) * (m % p)) % p;
        long long nr = ((n - r + 1) % p) * ((m - c + 1) % p) % p;
        
        long long ex = (nm - nr) % p;
        if (ex < 0) ex += p;
        
        long long ans = power(2, ex, MOD);
        cout << ans << "\n";
    }
    
    return 0;
}