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
    ll n,m;cin>>n>>m;
    ll mx = n, mn = n/2 + (n&1);
    ll r = mn%m == 0?0:m-(mn%m);

    if(mn+r >= mn  && mn+r <=mx){
        cout<<mn+r<<"\n";
    }else{
        cout<<-1<<"\n";
    }
    return 0;
}