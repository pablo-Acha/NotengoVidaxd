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
        string a;cin>>a;
        string b;cin>>b;
        string c;cin>>c;
        a = "0"+a;
        b = "0"+b;
        c = "0"+c;

        vector<vll> dp(a.size(),vll(b.size()));
        for (int i = 1; i < a.size(); i++)dp[i][0] = dp[i-1][0]+ (a[i] != c[i]);
        for (int i = 1; i < b.size(); i++)dp[0][i] = dp[0][i-1]+ (b[i] != c[i]);

        for (int i = 1; i < a.size(); i++)
        {
            for (int j = 1; j < b.size(); j++)
            {
                dp[i][j] = min(dp[i-1][j]+(c[i+j] != a[i]),dp[i][j-1]+(c[i+j] != b[j]));
            }
        }
        cout<<dp[a.size()-1][b.size()-1]<<"\n";

    }

    return 0;
}