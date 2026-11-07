#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll gaus(ll n){
    return (n*(n+1))/2;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vll arr(n),dp(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = arr[i];
            if(i+arr[i]<n){
                dp[i]+= dp[i+arr[i]];
            }
        }
        ll res = *max_element(dp.begin(),dp.end());
        cout<<res<<"\n";
    }

    return 0;
}