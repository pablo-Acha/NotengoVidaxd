#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr){cin>>a;}
        vector<vll> menor(n),mayor(n);
        if(n == 1){
            cout<<"NO\n";
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            if(i+arr[i]<n){
                mayor[i].push_back(i+arr[i]);
                menor[i+arr[i]].push_back(i);
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if(i-arr[i]>=0)
            {
                menor[i].push_back(i-arr[i]);
                mayor[i-arr[i]].push_back(i); 
            }
        }
        queue<ll> qu;
        qu.push(0);
        vll vis(n);
        vis[0] = 1;
        bool f = 0;
        while(!qu.empty()){
            ll x = qu.front();
            qu.pop();
            for(auto ni:mayor[x]){
                if(ni == n-1){f = 1;break;}
                if(vis[ni])continue;
                vis[ni] = 1;
                qu.push(ni+1);
            }
            if(f)break;
        }
        // ll h = 0;
        // for(auto x:mayor){
        //     cout<<h<<"| ";
        //     h++;
        //     for(auto a:x)
        //         cout<<a<<" ";
        //     cout<<"\n";
        // }
        // cout<<"\n";
        if(f){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}