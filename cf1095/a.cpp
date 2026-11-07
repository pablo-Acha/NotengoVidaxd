#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

const ll MOD = 676767677;
ll guas(ll n){return n*(n+1) /2;}
int main(){
        ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll sum= 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if(arr[i] == 1)continue;
            sum  = (sum+arr[i]) %MOD;

        }
        sum  = (sum+(arr[n-1] == 1))%MOD;
        cout<<sum<<"\n";
    }   
    return 0;
}