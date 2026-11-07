#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,w;cin>>n>>w;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll pre(n+1);
        for (int i = 0; i < n; i++)
        {
            pre[i+1] = arr[i]+pre[i];
        }
        // for(auto a:pre)cout<<a<<" ";
        // cout<<"\n";
        vll brr(2*w);
        ll mn = 1e10;
        for (ll i = 1,j = 1-w; j < n; i++,j++)
        {
            brr[i%(2*w)] += pre[min(i,n)]-pre[max(j,0LL)];
        }
        mn = *min_element(brr.begin(),brr.end());
        cout<<mn<<"\n";
        
    }
    return 0;
}