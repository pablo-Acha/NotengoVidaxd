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

    ll n,k;cin>>n>>k;
    vector<vll> dp(k+1,vll(min(k,n)+1));
    for (int i = 1; i <= k; i++)
    {
        dp[i][1] = 1;
    }
    
    for (int i = 1; i <= min(k,n); i++)
    {
        ll acc = 0;
        if(i!=1)for (int j = 1; j <= k; j++){
            dp[j][i]= (dp[j-1][i] + dp[j][i])%MOD;
        }
        if(i == min(k,n))break;
        for (int j = 1; j <= k; j++)
        {
            ll aux2 = (i*j)/(i+1)  +1;
            dp[aux2][i+1] = (dp[aux2][i+1] + dp[j][i])%MOD;
            ll aux= ((j*i)+k)/(i+1) +1;
            // cout<<j<<" "<<aux<<"\n";
            if(aux<=k)dp[aux][i+1] = (dp[aux][i+1] - dp[j][i] + MOD)%MOD; 
        }
        // for(auto v:dp){for(auto x:v)cout<<x<<" ";cout<<"\n";}
    }
        // for(auto v:dp){for(auto x:v)cout<<x<<" ";cout<<"\n";}

    ll res = 0;
    for (int i = 1; i <= k; i++)
    {
        res = (res+dp[i][min(n,k)])%MOD;
    }
    cout<<res<<"\n";

    return 0;
}