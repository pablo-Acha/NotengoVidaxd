#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n) { return n * (n + 1) / 2; }

const ll MOD =998244353;
ll modpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%MOD;
        a = a*a%MOD;
        b >>= 1;
    }
    return res;
}
ll C(int n, int x){
    x = min(x, n - x);

    ll num = 1;
    ll den = 1;

    for(int i = 1; i <= x; i++){
        num = num * (n - x + i) % MOD;
        den = den * i % MOD;
    }

    return num * modpow(den, MOD - 2) % MOD; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        string s;cin>>s;
        s = '0'+s + '0';
        ll res= 0;
        for (int i = 0; i < s.size(); i++)
        {
            ll cnt = 0;
            res+= s[i] == '1';
            if(s[i]=='0'){
                while(i<s.size() && s[i] == '0'){
                    cnt++;
                    i++;
                }
                i--;
                res+= (cnt/3);
            }
        }
        cout<<res<<"\n";
    }
}