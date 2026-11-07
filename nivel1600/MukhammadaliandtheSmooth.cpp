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
        vll crr(n);for(auto &a:crr)cin>>a;
        vector<vll> dp(n,vll(2));
        vll nuevo(n);nuevo[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            ll acc = 0;
            ll mn = 1e18;
        //     for (int i = 0; i < n; i++)
        // {
        //     cout<<dp[i][0]<<" ";
        // }cout<<"\n";
            for (int j = i-1; j >= 0; j--)
            {
                if(arr[j]<=arr[i])mn = min(dp[j][0]+acc,mn);
                acc +=crr[j];                
            }
            dp[i][0] = min(mn,acc);
            ll x =dp[i-1][0]+(arr[i-1]>arr[i]?crr[i]:0);
            ll y = dp[i-1][1]+(nuevo[i-1]>arr[i]?crr[i]:0);
            if(x<y){
                dp[i][1] = x;
                nuevo[i] = arr[i-1];
            }else if(y<x){
                dp[i][1] = y;
                nuevo[i] = nuevo[i-1];
            }else{
                dp[i][1] = x;
                nuevo[i] = min(arr[i-1],nuevo[i-1]);
            }
            nuevo[i] = max(arr[i],nuevo[i]);
        }
        // for(auto x:nuevo)cout<<x<<" ";cout<<"\n";
        // for (int i = 0; i < n; i++)
        // {
        //     cout<<dp[i][0]<<" ";
        // }cout<<"\n";
        // for (int i = 0; i < n; i++)
        // {
        //     cout<<dp[i][1]<<" ";
        // }cout<<"\n";
        cout<<min(dp[n-1][0],dp[n-1][1])<<"\n";
    }

    return 0;
}