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
    vll arr(n);for(auto &a:arr)cin>>a;
    vll brr(n);for(auto &a:brr)cin>>a;
    vll da(n),db(n);
    da[n-1] = arr[n-1];
    db[n-1] = brr[n-1];
    for (int i = n- 2; i >= 0; i--)
    {
        da[i] = max(da[i+1],min(arr[i],db[i+1]));   
        db[i] = min(db[i+1],max(brr[i],da[i+1]));   
    }
    // for(auto x:da)cout<<x<<" ";cout<<"\n";
    // for(auto x:db)cout<<x<<" ";cout<<"\n";
    if(da[0]>=0){
        cout<<da[0]<<"\n";
    }else if(db[0]<0){
        cout<<max(da[0],db[0])<<"\n";
    }else{
        cout<<0<<"\n";
    }

    return 0;
}