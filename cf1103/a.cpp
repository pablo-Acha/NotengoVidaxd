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
    while(t--)
    {   
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll mx = *max_element(arr.begin(),arr.end())  +1;
        ll mn = *min_element(arr.begin(),arr.end());
        cout<<mx-mn<<"\n";
    }
    return 0;
}