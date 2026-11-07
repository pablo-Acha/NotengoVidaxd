#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
const ll MOD  = 1e9 + 7;
long long restaModular(long long a, long long b) {
    return ((a - b) % MOD + MOD) % MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;cin>>n;
    vll arr(n);for(auto &a:arr)cin>>a;
    vll brr = arr;
    sort(brr.begin(),brr.end());
    ll l = 1e9,r = -1;
    ll aux = -1;
    bool f = 0;
    for (ll i = 0; i < n; i++)
    {
        if(arr[i]!=brr[i]){
            f = 1;
            l = min(i,l);
            r  =max(i,r);
        }
    }
    if(!f){
        cout<<"yes\n";
        cout<<"1 1\n";
        return 0;
    }
    // cout<<l<<" "<<r<<"\n";
    reverse(arr.begin()+l,arr.begin()+r+1);
    // for(auto a:arr)cout<<a<<" ";
    // cout<<"\n";
    f = 0;
    for (ll i = 0; i < n; i++)
    {
        if(arr[i]!=brr[i]){
            f = 1;
        }
    }
    if(f){
        cout<<"no\n";
    }else{
        cout<<"yes\n";
        cout<<l+1<<" "<<r+1<<"\n";
    }

    return 0;
}