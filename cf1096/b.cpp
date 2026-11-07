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
        ll n;cin>>n;
        string s;cin>>s;
        ll x = 0;
        for (int i = 0; i < n; i++)
        {
            if(s[i] == '('){
                x++;
            }else{
                x--;
            }
        }
        if(x == 0){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
       
    return 0;
}