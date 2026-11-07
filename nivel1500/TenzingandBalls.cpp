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
    while (t--)
    {
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll dp(n+1);
        vll last(n+1,-1);
        for (int i = n - 1; i >= 0; i--)
        {
            if(last[arr[i]] == -1){
                dp[i] = dp[i+1];
            }else{
                ll dif = +last[arr[i]]-i;
                dp[i] = max(dp[last[arr[i]]]+dif,dp[last[arr[i]]+1]+dif+1);
                dp[i] = max(dp[i],dp[i+1]);
            }
            last[arr[i]] = i;
        }
        cout<<dp[0]<<"\n";
    }
    

    return 0;
}