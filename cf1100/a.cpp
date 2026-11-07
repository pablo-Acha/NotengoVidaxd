#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll gaus(ll n){return n*(n+1) /2;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll mn = 1e9;
        ll mx = -1;
        for (int i = 0; i < n; i++)
        {
            ll a;cin>>a;
            mn = min(mn,a);
            mx = max(mx,a);
        }
        if(mn == mx){
            cout<<"0\n";
        }else{
            cout<<(mx-mn+1)/2<<"\n";
        }
    }
    return 0;
}