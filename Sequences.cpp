#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
const ll MOD  = 1e9 + 7;
long long restaModular(long long a, long long b) {
    return ((a - b) % MOD + MOD) % MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vll potencias(500003);
    vll sumas(500003);
    potencias[0] = 1;
    sumas[0] = 0;
    for (int i = 1; i < 500003; i++)
    {
        potencias[i] = (potencias[i-1]*2)%MOD;
    }
    for (int i = 1; i < 500003; i++)
    {
        sumas[i] = (((2*sumas[i-1])%MOD)+potencias[i-1])%MOD;
    }
    string s;cin>>s;
    ll signos = 0;
    ll unos = 0;
    ll n = s.size();
    ll res = 0;
    ll k = 0;
    for (int i = 0; i < n; i++)
    {
        k += s[i] == '?';
    }
    
    for (int i = n - 1; i >= 0; i--)
    {
        ll dis = n-1-i - unos;
        if(s[i] == '1'){
            ll val = restaModular(((potencias[signos]*dis)%MOD),sumas[signos]);
            res=  (((val*potencias[k-signos])%MOD)+res)%MOD; 
        }else if(s[i] == '?'){
            ll val = restaModular(((potencias[signos]*dis)%MOD),sumas[signos]);
            res=  (((val*potencias[k-signos-1])%MOD)+res)%MOD;
        }   
        unos+= s[i] == '1';
        signos+= s[i] == '?';
    }
    cout<<res<<"\n";
    
    return 0;
}