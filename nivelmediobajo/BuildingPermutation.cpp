#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int n;cin>>n;
    vll arr(n);for(auto &a:arr)cin>>a;
    sort(arr.begin(),arr.end());
    ll res = 0; 
    for (ll i = 0,j = 1; i < n; i++,j++)
    {
        res+= abs(j-arr[i]);
    }
    cout<<res<<"\n";
    return 0;
}