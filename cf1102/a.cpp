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
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        
        sort(arr.begin(),arr.end(),greater<ll>());
        bool f= 1;
        for (int i = 1; i < n-1; i++)
        {
            if(arr[i-1]%arr[i] != arr[i+1]){f = 0;break;}
        }
        if(f){
            cout<<arr[0]<<" "<<arr[1]<<"\n";
        }else{
            cout<<"-1\n";
        }
        
    }
    return 0;
}