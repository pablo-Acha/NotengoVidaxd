#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){

    ll n;cin>>n;
    vll arr(n);for(auto &a:arr)cin>>a;
    sort(arr.begin(),arr.end());
    ll q;cin>>q;
    for (int i = 0; i < q; i++)
    {
        ll a;cin>>a;
        ll res = upper_bound(arr.begin(),arr.end(),a)-arr.begin();
        cout<<res<<"\n";
    }
    
    
    return 0;
}