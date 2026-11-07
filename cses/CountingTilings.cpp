#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

const ll  MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;cin>>m>>n;
    vector<vll> dp(n+1,vll(m+1));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 1;
    }
    
    
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= m; x++)
        {
            if(x>1){
                dp[y][x] = ((x-2>=0?dp[y][x-2]:0) +(y-1>=0?dp[y-1][x]:0) -(y-1>=0 && x-2>=0?dp[y-1][x-2]:0) +2*MOD)%MOD;    
            }
            if(y>1){
                dp[y][x] = (dp[y][x] + ((x-1>=0?dp[y][x-1]:0) +(y-2>=0?dp[y-2][x]:0) -(y-2>=0 && x-1>=0?dp[y-2][x-1]:0) +2*MOD)%MOD)%MOD;    
            }
        }
    }
    for(auto v:dp){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    return 0;
}