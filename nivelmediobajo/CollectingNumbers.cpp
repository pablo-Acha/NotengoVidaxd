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
    vll brr(n+1,1);
    brr[0] = 0;
    ll cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if(!brr[arr[i]-1]){
            cnt++;
        }
        brr[arr[i]] = 0;
    }
    cout<<cnt<<"\n";
    return 0;
}