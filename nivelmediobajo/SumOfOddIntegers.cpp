#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        for (ll i = 0,j = 1; i < k; i++,j+=2)
        {
            n-=j;
            if(n<0)break;
        }
        if(n<0 || n&1)cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}