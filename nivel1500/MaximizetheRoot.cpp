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
        vll arr(n);for(auto &a:arr)cin>>a;
        vll p(n);
        vll cant(n);
        vll dp(n,1e10);
        for (int i = 0; i < n-1; i++)
        {
            cin>>p[i+1];
            p[i+1]--;
            cant[p[i+1]]++;
        }
        queue<ll> q;
        for (int i = 0; i < n; i++)
        {
            if(cant[i] == 0){
                q.push(i);
                dp[i] = arr[i];
            }
        }
        // for(auto y:dp){
        //     cout<<y<<" ";
        // }
        // cout<<"\n";
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            ll aux = arr[x]+ dp[x];
            if(dp[x]>arr[x])
            {
                // cout<<x<<" ";
                dp[x] = arr[x] + (dp[x]-arr[x])/2;
            }
            arr[x] = aux;
            if(x == 0)break;
            cant[p[x]]--;
            dp[p[x]] = min(dp[x],dp[p[x]]);
            if(cant[p[x]] == 0){
                q.push(p[x]);
            }
        }
        // for(auto y:dp){
        //     cout<<y<<" ";
        // }
        // cout<<"\n";
        // for(auto x:p){
        //     cout<<x<<" ";
        // }
        // cout<<"\n";
        cout<<arr[0]<<"\n";
    }

    return 0;
}