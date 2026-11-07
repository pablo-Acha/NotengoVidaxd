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

    
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vector<vll> dp(n,vll(2,0));
        for (int i = 0; i < n; i++)
        {
            ll mn1 = i>0?dp[i-1][1]:0;
            if(i>1){
                ll aux = min(dp[i-2][0],dp[i-2][1])+1;
                mn1 = min(aux,mn1);
            }
            dp[i][0] = (i>0?mn1:0)+!(arr[i]&1);
            ll mn2 = i>0?dp[i-1][0]:0;
            if(i>1){
                ll aux = min(dp[i-2][0],dp[i-2][1])+1;
                mn2 = min(aux,mn2);
            }
            dp[i][1] = (i>0?mn2:0)+!((arr[i]>>1)&1);
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
        // }
        
        cout<<min(dp[n-1][0],dp[n-1][1])<<"\n";
    

    return 0;
}