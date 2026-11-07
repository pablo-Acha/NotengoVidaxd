#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

long long f(ll a,ll b,ll n){
    ll i = 1;
    while(a<=n && b<=n){
        if(i&1){
            a+=b;
        }else{
            b+=a;
        }
        i++;
    }
    return i;
}

int main(){
    int t;cin>>t;
    while(t--){
        long long a,b,n;cin>>a>>b>>n;
        ll res = min(f(a,b,n),f(b,a,n));
        cout<<res-1<<"\n";
    }
    
    return 0;
}