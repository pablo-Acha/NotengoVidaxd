#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;


int main(){
    ll n;cin>>n;
    vll arr(n);
    cin>>arr[0];
    for (ll i = 1,a; i < n; i++)
    {
        cin>>a;
        arr[i]+= arr[i-1]+a;
    }
    ll m;cin>>m;
    for (ll i = 0,x; i < m; i++)
    {
        cin>>x;
        ll res = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        cout<<res+1<<"\n";
    }
    
    return 0;
}