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
        multiset<ll> ml;    
        vll arr(n);for(auto &a:arr)cin>>a,ml.insert(a);
        for (int i = n - 1; i >= 0; i--)
        {
            auto x = ml.upper_bound(arr[i]);
            
        }
        
    }   
       
    return 0;
}