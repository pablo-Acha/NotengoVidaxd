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
        vll val(n);for(auto &a:val)cin>>a;
        vector<vll> grafo(n);
        vll pa(n);
        vll vis(n);
        vector<vll>dp(n,vector<ll>(2));
        for (int i = 0; i < n-1; i++)
        {
            ll a,b;cin>>a>>b;
            a--,b--;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }
        queue<ll> qu;
        for(auto x:grafo[0]){
            qu.push(x);
            vis[x] = 1;
            pa[x] = 0;
        }
        dp[0][0] = 0;
        dp[0][1] = val[0];
        vis[0] = 1;
        // qu.push();
        while(!qu.empty()){
            auto x = qu.front();
            qu.pop();
            ll p = pa[x];
            // if(x == 1){
            //     cout<<p<<"\n";
            //     cout<<dp[p][1]<<"\n";
            //     cout<<dp[p][0]<<"\n";
            // }
            dp[x][0] = min(val[x]-dp[p][1],val[x]);
            dp[x][1] = max(val[x]-dp[p][0],val[x]);
            for(auto ni:grafo[x])
            {
                if(vis[ni])continue;
                pa[ni] = x;
                vis[ni] = 1;
                qu.push(ni);
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout<<dp[i][1]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}