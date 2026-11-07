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
        string s;cin>>s;
        s = '0'+s;
        n++;
        bool f = 1;
        for (int i = 1; i < n; i++)
        {
            if(s[i] == s[i-1] && s[i] == '0'){
                f = 0;break;
            }
        }
        if(!f){
            cout<<-1<<"\n";
            continue;
        }
        vector<vll> dp(4,vll(n));
        for (int i = 1; i < n; i++)
        {
            if(s[i-1] == '0'){
                dp[1][i]= max(dp[0][i-1],1LL);
                dp[2][i]= max(dp[0][i-1],2LL);
                dp[3][i] = max(dp[0][i-1],3LL);
            }else if(s[i-1] == '+'){
                if(s[i] == '-'){
                    dp[1][i]= min(min(max(dp[1][i-1],2LL),max(dp[2][i-1],3LL)),max(dp[3][i-1],4LL));
                    dp[2][i]= min(min(max(dp[1][i-1],3LL),max(dp[2][i-1],4LL)),max(dp[3][i-1],5LL));
                    dp[3][i]= min(min(max(dp[1][i-1],4LL),max(dp[2][i-1],5LL)),max(dp[3][i-1],6LL));
                }else if(s[i] == '+'){
                    dp[1][i] = min(max(dp[2][i-1],1LL),max(dp[3][i-1],2LL));
                    dp[2][i] = min(max(dp[1][i-1],1LL),max(dp[3][i-1],1LL));
                    dp[3][i] = min(max(dp[2][i-1],1LL),max(dp[1][i-1],2LL));
                }else{
                    dp[0][i] = min(min(max(dp[2][i-1],2LL),max(dp[1][i-1],1LL)),dp[3][i-1]);
                }
            }else{
                if(s[i] == '+'){
                    dp[1][i]= min(min(max(dp[1][i-1],2LL),max(dp[2][i-1],3LL)),max(dp[3][i-1],4LL));
                    dp[2][i]= min(min(max(dp[1][i-1],3LL),max(dp[2][i-1],4LL)),max(dp[3][i-1],5LL));
                    dp[3][i]= min(min(max(dp[1][i-1],4LL),max(dp[2][i-1],5LL)),max(dp[3][i-1],6LL));
                }else if(s[i] == '-'){
                    dp[1][i] = min(max(dp[2][i-1],1LL),max(dp[3][i-1],2LL));
                    dp[2][i] = min(max(dp[1][i-1],1LL),max(dp[3][i-1],1LL));
                    dp[3][i] = min(max(dp[2][i-1],1LL),max(dp[1][i-1],2LL));
                }else{
                    dp[0][i] = min(min(max(dp[2][i-1],2LL),max(dp[1][i-1],1LL)),dp[3][i-1]);
                }
            }
        }
        ll res = 1e9;
        // for (int i = 0; i < 3; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        if(s[n-1] == '0'){
            res = dp[0][n-1];
        }else{
            for (int i = 1; i <= 3; i++)
            {
                res = min(dp[i][n-1],res);                
            }
        }
        cout<<res<<"\n";
        
        
    }

    return 0;
}