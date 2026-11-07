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
        vll dp(n+1);
        dp[n-1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if(arr[i]+i+1>n){
                dp[i] = dp[i+1]+1;
            }else{
                dp[i] = min(dp[i+1]+1,dp[arr[i]+i+1]);
            }
        }
        cout<<dp[0]<<"\n";
    }

    return 0;
}