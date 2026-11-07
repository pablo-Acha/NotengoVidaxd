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
        vector<vll> dp(4,vll(n,1e9));
        dp[0][0] = arr[0] == 1;
        for (int i = 1; i < n; i++)
        {
            dp[0][i] = min(dp[2][i-1],dp[3][i-1])+(arr[i] ==1);
            dp[1][i] = dp[0][i-1]+(arr[i] ==1);
            dp[2][i] = min(dp[0][i-1],dp[1][i-1]);
            dp[3][i] = dp[2][i-1];
        }
        ll mn = 1e10;
        for (int i = 0; i < 4; i++)
        {
            mn = min(dp[i][n-1],mn);
        }
        
        cout<<mn<<"\n";

    }

    return 0;
}