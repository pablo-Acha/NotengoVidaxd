#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()
const ll MOD = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n+1);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i+1];
        }
        vector<vll> dp(2,vll(n+1));
        dp[0][0] = dp[1][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            if(arr[i] == arr[i-1]){
                dp[1][i] = dp[1][i-1]; 
            }
            if(i>1 && arr[i]-1 == arr[i-2]){
                dp[1][i] = (dp[1][i]+dp[0][i-1])%MOD; 
            }
            dp[0][i] = dp[1][i-1];
        }
        bool f= 1;
        for (int i = 2; i <= n; i++)
        {
            if(dp[1][i] == 0 && dp[1][i-1] == 0){
                f = 0;
                break;
            }
        }
        if(!f){
            cout<<"0\n";
        }else{
            ll res = (dp[0][n]+dp[1][n])%MOD; 
            cout<<res<<"\n";
        }
        

    }

    return 0;
}