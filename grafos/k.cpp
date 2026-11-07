#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

const ll INF= 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m,q;cin>>n>>m>>q;
    vector<vll> dp(n+1,vll(n+1,INF));
    for (int i = 0; i < m; i++)
    {
        ll a, b,w;cin>>a>>b>>w;
        dp[a][b] = min(w,dp[a][b]);
        dp[b][a] = min(w,dp[b][a]);
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }
    

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <=n; j++)
            {
                if(dp[i][k] == INF || dp[k][j] == INF)continue;       
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }            
        }
    }

    for (int i = 0; i < q; i++)
    {
        ll a,b;cin>>a>>b;
        cout<<(dp[a][b] ==INF?-1:dp[a][b]) <<"\n";
    }
    
    
    return 0;
}