#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll gaus(ll n){
    return (n*(n+1))/2;
}
const ll MOD =998244353; 

ll op(ll n,ll x){
    ll res = 0;
    if(x<=0)return 0;
    ll iz=(x/4) +1 ;
    ll der=(n/4) +1 -iz+(n%4==3);
    iz %=MOD;
    der %=MOD;
    res = (iz*der)%MOD;
    
    return res%MOD;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,x;cin>>n>>x;
        ll res = 0;
        res = op(n,x);
        res = (res+op(n-2,x-2))%MOD;
        
        // res= (op(n-1,x,2)+res)%MOD;
        // res= (op(n,x,3)+res)%MOD;

        cout<<res<<"\n";
    }
    
    
    return 0;
}