#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

bool fun(ll ind,ll tam ,pll left,pll right){
    auto [l,r] = left;
    auto [xl,xr]= right;
    ll contra = tam-ind+1;
    
    return (ind<l || ind>r) && (contra<xl || contra>xr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<pll> left(n);
        vector<pll> right(n);
        for (int i = 0; i < n; i++)
        {
            ll l,r;cin>>l>>r;
            left[i] = {l,r};
            cin>>l>>r;
            right[i] = {l,r};
        }
        vector<vll> dp(n+1,vll(n+1));
        for (ll x = 1; x < n+1; x++)
        {
            for (ll y = 1; y < n+1; y++)
            {
                ll indice = min(dp[y][x-1]+1LL,y);
                // if(x == 4 && y == 4){
                //     cout<<indice<<"---\n";
                // }
                dp[y][x] = (fun(indice,y,left[x-1],right[x-1])? indice:dp[y][x-1] );
            }
        }

        ll res = 0;
        // for (int i = 0; i < n+1; i++)
        // {
        //     for (int j = 0; j < n+1; j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
              
        for (ll i = 1; i < n+1; i++)
        {
            if(dp[i][dp.size()-1] == i){
                res =max(dp[i][dp.size()-1],res);
            }
        }
        cout<<res<<"\n";
    }

    return 0;
}