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
    ll t;cin>>t;
    while(t--){
        string s;cin>>s;
        ll n = s.size();
        ll cnt = 0;
        for (int i = 1; i < n; i++)
        {
            if(s[i]==s[i-1])cnt++;
        }
        if(cnt<=2){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}