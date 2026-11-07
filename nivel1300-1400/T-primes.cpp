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
    ll t;cin>>t;
    vll primos(1e6+1,1);
    for (ll i = 2; i <= 1e6; i++)
    {
        if(primos[i]==0)continue;
       for (ll j = i*2; j <= 1e6; j+=i)
       {
            primos[j] = 0;
       }
        
    }
    
    while(t--){
        ll n;cin>>n;
        ll raiz = sqrt(n);
        if(raiz*raiz == n && primos[raiz] && raiz!=1){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    
    return 0;
}