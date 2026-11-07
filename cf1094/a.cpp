#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
ll guas(ll n){return n*(n+1) /2;}
int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);
        bool f = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            if(arr[i] == 100)f = 1;
        }
        if(f){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }   
    return 0;
}