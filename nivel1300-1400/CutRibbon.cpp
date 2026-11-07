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
    ll n;vll arr(3);
    cin>>n;
    for(auto &a:arr)cin>>a;
    vll dp(n+1,-1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        ll mx = -1;
        for(auto x:arr){
            if(i-x<0 || dp[i-x] == -1)continue;
            mx = max(mx,dp[i-x]+1);
        }
        dp[i] = mx;
    }
    // for(auto a:dp){
    //     cout<<a<<" ";
    // }
    // cout<<"\n";
     cout<<dp[n]<<"\n";
    return 0;
}