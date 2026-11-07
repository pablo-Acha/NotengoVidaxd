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

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        map<ll,ll> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        vll brr = arr;
        sort(all(brr));
        brr.erase(unique(all(brr)),brr.end());
        brr.push_back(1e18);
        for (int i = 0; i < brr.size(); i++)
        {
            if(brr[i]!=i){
                brr.erase(brr.begin()+i,brr.end());
                brr.push_back(i);
            }
        }
        ll m = brr.size();
        vll dp(m);
        // for(auto x:brr)cout<<x<<" ";cout<<"\n";
        
        for (int i = m - 2; i >= 0; i--)
        {
            ll mn = 1e18;
            for (int j = i+1; j < m; j++)
            {
                mn = min(mn,dp[j]+mp[brr[i]]*brr[j]);
            }            
            dp[i]=mn;
        }
        // for(auto x:dp)cout<<x<<" ";cout<<"\n";

        cout<<dp[0]-brr[m-1]<<"\n";
        
    }

    return 0;
}