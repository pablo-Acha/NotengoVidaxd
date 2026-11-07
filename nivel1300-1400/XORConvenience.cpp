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
        ll n;cin>>n;
        vll arr(n);
        arr[n-1] = 1;
        if(n&1){
            arr[0] = n-1;
        }else{
            arr[0] = n;
        }
        for (int i = 1; i < n-1; i++)
        {
            arr[i] = (i+1)^1;
        }
        for(auto a:arr)cout<<a<<" ";
        cout<<"\n";
    }   
    
    return 0;
}