#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,x,y,z;cin>>n>>x>>y>>z;
        ll a = n/(x+y) + (n%(x+y)>0);
        if(a<=z){
            cout<<a<<"\n";
            // cout<<"xx"<<"\n";
        }else{
            ll aux = n-(x*z);
            aux = (aux/(x+(y*10)))+(aux%(x+(y*10))>0);
            ll res =min(aux+z,a);
            cout<<res<<"\n";
        }
    }
    return 0;
}