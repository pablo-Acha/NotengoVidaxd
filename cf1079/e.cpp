#include<bits/stdc++.h>
using namespace std;
#define rnl "\n"
typedef long long ll;
typedef vector<ll> vll;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        sort(arr.begin(),arr.end());
        set<ll> x;
        for(auto a:arr){
            x.insert(a);
        }
        vll brr;
        for(auto h:x){
            brr.push_back(h);
        }
        vll dp(n+1,1e10);
        for (int i = 0; i < brr.size(); i++)
        {
            dp[brr[i]] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i]; j < n/arr[i]; j++)
            {
                if(dp[j] == 1e10)continue;
                dp[j*arr[i]] = min(dp[j*arr[i]],dp[j]+1);
            }   
        }
        for (int i = 1; i <= n; i++)
        {
            if(dp[i] == 1e10){cout<<-1<<" ";continue;}
            cout<<dp[i]<<" ";
        }
        cout<<rnl;
        
    }
    
    return 0;
}