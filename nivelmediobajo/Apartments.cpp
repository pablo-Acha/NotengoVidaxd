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
    ll n,m,k;cin>>n>>m>>k;
    vll arr(n),brr(m);
    for(auto &a:arr)cin>>a;
    for(auto &a:brr)cin>>a;
    ll i = 0,j = 0;
    ll res = 0;
    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());
    while((i<n && j<m)){
        while((i<n && j<m) && brr[j]<arr[i]-k){
            j++;
        }
        if((i<n && j<m) &&arr[i]-k <= brr[j] && arr[i]+k>=brr[j]){
            res++;
            i++;
            j++;
            continue;
        }
        if((i<n && j<m) && arr[i]+k<brr[j])i++;

    }
    cout<<res<<"\n";
    return 0;
}