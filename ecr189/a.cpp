#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll,ll> vll;

ll gaus(ll n){
    return (n*(n+1))/2;
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;cin>>n;
    while (n--)
    {
        ll a,b;cin>>a>>b;
        if(a*2 == b){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
    
    return 0;
}