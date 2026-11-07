#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll a,b;cin>>a>>b;
        if((a&1)&& (b&1)){
            cout<<"NO\n";
        }   else{
            cout<<"YES\n";
        }
    }
       
    return 0;
}