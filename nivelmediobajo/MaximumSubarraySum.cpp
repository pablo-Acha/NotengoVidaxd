#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll gaus(ll n){
    return (n*(n+1))/2;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;cin>>n;
    vll arr(n);for(auto &a:arr)cin>>a;
    ll sum = 0;
    ll mx = 0;
    for (int i = 0; i < n; i++)
    {
        if(sum+arr[i]<=0)
        {sum = 0;
        continue;}
        sum+=arr[i];
        mx = max(sum,mx);
    }
    if(mx ==0){
        mx = *max_element(arr.begin(),arr.end());
    }
    cout<<mx<<"\n";
    return 0;
}