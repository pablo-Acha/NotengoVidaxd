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
        ll n,m;cin>>n>>m;
        vll arr(n);for(auto &a:arr)cin>>a;
        vector<vector<pll>> grafo(n);
        vll grado(n);
        for (int i = 0; i < m; i++)
        {
            ll a,b,w;cin>>a>>b>>w;
            a--,b--;
            grafo[a].push_back({b,w});
        }
        ll l = 0,r = 1e9, mid = 0;
        while(l<=r){
            mid = (l+r)/2;
            vll dp(n,-1);dp[0] = 0;
            for (int i = 0; i < n; i++){
                if(dp[i]!=-1){
                    ll falta = mid-dp[i];
                    ll aux = min(falta,arr[i]);
                    dp[i]+= aux;
                    for(auto [ni,w]:grafo[i]){
                        if(dp[i]>=w){
                            dp[ni] = max(dp[i],dp[ni]);
                        }
                    }
                }
            }
            if(dp[n-1]!=-1){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        cout<<(l>1e9?-1:l)<<"\n";
    }

    return 0;
}