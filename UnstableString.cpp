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
        string s;cin>>s;
        ll n = s.size();
        s = 'x'+s;
        vector<vll> dp(2,vll(n+1));
        ll res = 0;
        for (int i = 1; i <= n; i++)
        {
            if(s[i] == '?'){
                dp[0][i] = dp[1][i-1]+1;
                dp[1][i] = dp[0][i-1]+1;
            }else if(s[i] == '0'){
                dp[0][i] = dp[1][i-1]+1;
            }else{
                dp[1][i] = dp[0][i-1]+1;
            }
            res+= max(dp[0][i],dp[1][i]);
        }
        cout<<res<<"\n";
    }

    return 0;
}