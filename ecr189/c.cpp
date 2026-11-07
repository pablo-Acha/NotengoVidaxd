#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll gaus(ll n){
    return (n*(n+1))/2;
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        string a,b;cin>>a>>b;
        vll dp(n),h(n),v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] += a[i]!=b[i];
            if(i>0) h[i] += (a[i]!=a[i-1])+(b[i]!=b[i-1]);
        }
        if(n == 1){
            dp[0] = v[0];
        }else if(n == 2){
            dp[0] = v[0];
            dp[1] = min(v[1]+dp[0],h[1]);
        }else{
            dp[0] = v[0];
            dp[1] = min(v[1]+dp[0],h[1]);
            for (int i = 2; i < n; i++)
            {
                dp[i] = min(v[i]+dp[i-1],h[i]+dp[i-2]);
            }
        }
        cout<<dp[n-1]<<"\n";
        
    }
    
    
    return 0;
}