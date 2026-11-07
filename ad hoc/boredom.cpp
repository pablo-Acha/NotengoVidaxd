#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
    int n;cin>>n;
    map<ll,ll> mp;
    for (ll i = 0,a; i < n; i++)
    {
        cin>>a;
        mp[a]++;
    }
    vector<pair<ll,ll>> arr;
    for(auto &[a,b]:mp){
        arr.push_back({a,b});
    }
    int m = arr.size();
    if(m== 1){
        cout<<arr[0].second*arr[0].first<<"\n";
        return 0;
    }
    vll dp(m);
    dp[0] = arr[0].second*arr[0].first;
 
    for (int i = 1; i < m; i++)
    {
        dp[i] = arr[i].second*arr[i].first;
        int h = 2;
        int j = i-1;
        vector<ll> aux;
        while(j>=0 && h){
            if(arr[i].first-1 != arr[j].first){
                h--;
                aux.push_back(dp[j]);
            }
            j--;
        }
        if(aux.size()>0)dp[i] += (*max_element(aux.begin(),aux.end()));

    }
    ll res = max(dp[m-1],dp[m-2]);
    cout<<res<<"\n";
    return 0;
}