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
    vll arr(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    vector<vll> dp(n+1,vll(n+1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if(j == 0){
                ll mx = 0;
                for (int h = 0; h <= i-1; h++)
                {
                    mx = max(dp[h][i-1],mx);
                }   
                dp[j][i]  = mx;
            }else{
                dp[j][i] = (dp[j-1][i-1]+arr[i]) - (j*2 -1);  
            }  
        }
    }
    ll res =0; 
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    for (int i = 0; i <= n; i++)
    {
        res = max(dp[i][n],res); 
    }
    cout<<res<<"\n";
    

    return 0;
}