#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()


ll k;
void dfs1(ll x,ll p,vll &val,vector<vll> &arbol,vll &dp){
    ll sum = 1;
    for(auto ni:arbol[x]){
        if(ni == p)continue;
        dfs1(ni,x,val,arbol,dp);        
        sum += val[ni];
        
        dp[x]+= dp[ni];
    }
    if(sum>=k){
        dp[x]++;
    }
    val[x] = sum;
    // if(x!=0)dp[x]= max(0LL,val[x]-k+1);
}

void dfs2(ll x,ll p,vll &val,vector<vll> &arbol,vll &dp,ll ant){
    ll n =  arbol.size();
    if(dp[x] == 0)dp[x]++;
    dp[x] += ant;
    for(auto ni:arbol[x]){
        if(ni == p)continue;
        dfs2(ni,x,val,arbol,dp,dp[x]-(n-val[ni]<k)-dp[ni]);        
    }
    // if(x!=0)dp[x]= max(0LL,val[x]-k+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n>>k;
        vector<vll> arbol(n);
        for (int i = 0; i < n-1; i++)
        {
            ll a,b;cin>>a>>b;
            a--,b--;
            arbol[a].push_back(b);
            arbol[b].push_back(a);
        }
                
        vll val(n);
        vll dp(n);
        dfs1(0,0,val,arbol,dp);
        // for(auto x:val){cout<<x<<" ";}cout<<"\n";
        // for(auto x:dp){cout<<x<<" ";}cout<<"\n";
        dfs2(0,0,val,arbol,dp,0);
        // for(auto x:val){cout<<x<<" ";}cout<<"\n";
        // for(auto x:dp){cout<<x<<" ";}cout<<"\n";
        ll res = accumulate(all(dp),0LL);
        cout<<res<<"\n";

    }

    return 0;
}