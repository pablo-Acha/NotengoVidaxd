#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
// typedef  pair<ll,ll> pii;
typedef  pair<ll,ll> pll;
// typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll n;cin>>n;
    vll arr(n+1);
    for (ll i = 2; i <= n; i++)
    {
        ll a;cin>>a;
        arr[i]= a;
    }
    vll dp(n+1);
    vll cant(n+1,1);
    
    vll fx(n+1);
    for (ll i = n; i >= 2; i--)
    {
        dp[arr[i]] += dp[i]+cant[i];
        cant[arr[i]] += cant[i];
    }
    // for(auto x:cant)cout<<x<<" ";cout<<"\n";
    for (ll i = 2; i <= n; i++)
    {
        ll p = arr[i];
        dp[i] = dp[p]+n-2*cant[i];
    }
    vll mx1(n+1);
    vll mx2(n+1);
    for(ll i = n; i >= 1; i--){
        fx[i] = max(fx[i], mx1[i] + mx2[i]);
        if(i > 1){
            ll p = arr[i];
            fx[p] = max(fx[p], fx[i]);
            ll d = mx1[i]+1;
            if(d > mx1[p]){
                mx2[p]=mx1[p];
                mx1[p]= d;
            }else if(d > mx2[p]){
                mx2[p]= d;
            }
        }
    }
    
    ll res = 0;
    for (ll i = 1; i <= n; i++)
    {
        res+=dp[i];
    }
    // dfs3(1,dist,fx,grafo);
    cout<<res/2<<"\n";
    for (ll i = 1; i <= n; i++)
    {
        cout<<fx[i];
        if(i<n)cout<<" ";
    }
    cout<<endl;
    
    return 0;
}