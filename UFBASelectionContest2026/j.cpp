#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;cin>>n;
    vll arr(n),brr(n);for(auto &a:arr)cin>>a; for(auto &b:brr)cin>>b;
    ll mx = 0;
    ll mn = 0;
    map<ll,ll> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]+brr[i]]++;
        mn = max(mn,min(arr[i],brr[i])+1);
        // mx = max(mx,mp[arr[i]+brr[i]]);
    }
    // cout<<mn<<"\n";
    for(auto [k,v]:mp){
        if(k<mn)continue;
        mx = max(mx,v);
    }
    cout<<(n-mx)<<"\n";

    return 0;
}