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
        ll n,k;cin>>n>>k;
        vll arr(n);
        vll brr(n);
        for(auto &x:arr)cin>>x;
        for(auto &x:brr)cin>>x;
        
        ll act = 0;
        ll mx= -1e18;
        vll dp(n,-1e18),dpp(n,-1e18);
        for (int i = 0; i < n; i++)
        {
            dp[i] = act;
            act+= arr[i];
            if(act<0){
                act = 0;
            }
            if(act>mx){
                mx = act;
            }
        }
        act = 0;
        for (int i = n-1; i >=0; i--)
        {
            dpp[i] = act;
            act+= arr[i];
            if(act<0){
                act = 0;
            }
        }
        if(mx == 0){
            ll res= *max_element(all(arr));
            if(k&1){
                for (int i = 0; i < n; i++)
                {
                    res = max(arr[i]+brr[i],res);    
                }
            }
            cout<<res<<"\n";
            continue;
        }
        if(!(k&1)){            
            cout<<mx<<"\n";
            continue;
        }
        ll res = -1e18;
        for (int i = 0; i < n; i++)
        {
            res = max(dp[i]+dpp[i]+arr[i]+brr[i],res);
        }
        cout<<res<<"\n";
        
    }

    return 0;
}