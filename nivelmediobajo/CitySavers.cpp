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
    vll arr(n+1),brr(n);
    for (int i = 0; i <= n; i++)
    {
        cin>>arr[i];
    }
    for(auto &a:brr)cin>>a;
    ll sum = accumulate(arr.begin(),arr.end(),0LL);
    for (int i = 0; i < n; i++)
    {
        ll aux = min(arr[i],brr[i]);
        arr[i]-=aux;
        brr[i]-=aux;
        aux = min(arr[i+1],brr[i]);
        arr[i+1]-=aux;        
    }
    ll sum2 = accumulate(arr.begin(),arr.end(),0LL);
    ll save = sum-sum2;
    cout<<save<<"\n";
    return 0;   
}