#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

ll longestCommonSubsecuence(vll &arr, vll &brr) {
    int n = arr.size();
    int m = brr.size();
    // ll ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i - 1] == brr[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }


    return dp[n][m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        
        string s;cin>>s;
        string c;cin>>c;
        vll arr(s.size()),brr(c.size());
        ll acc = 0,bcc= 0;
        for (int i = 0; i < s.size(); i++)
        {
            ll aux = s[i]-'0';
            acc = (acc+aux)%10;
            arr[i]= acc;
        }
        for (int i = 0; i < c.size(); i++)
        {
            ll aux = c[i]-'0';
            bcc = (bcc+aux)%10;
            brr[i]= bcc;
        }
        // for(auto x:arr){
        //     cout<<x<<" ";
        // }
        // cout<<"\n";
        // for(auto x:brr){
        //     cout<<x<<" ";
        // }
        // cout<<"\n";
        if(brr[brr.size()-1]!=arr[arr.size()-1]){
            cout<<-1<<"\n";
        }else{
            ll res = longestCommonSubsecuence(arr,brr);
            cout<<res<<"\n";
        }
    }

    return 0;
}