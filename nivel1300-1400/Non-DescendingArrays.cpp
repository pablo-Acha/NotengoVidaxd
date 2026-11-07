#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    vll pre(102);
    pre[0] = 1;
    for (int i = 1; i < 102; i++)
    {
        pre[i] = (pre[i-1]*2)%MOD;
    }
    
    while(t--){
        ll n;cin>>n;
        vll arr(n+2),brr(n+2);
        vll vis(n+2);
        for (int i = 1; i <= n; i++)cin>>arr[i];
        for (int i = 1; i <= n; i++)cin>>brr[i];
        brr[n+1] = arr[n+1] = 1e9;
        ll cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            // if(arr[i]<brr[i])swap(arr[i],brr[i]);
            ll mn = min(arr[i],brr[i]);
            if(mn>= max(arr[i-1],brr[i-1]) ){         
                cnt++;
            }else{
            }
        }
        

        // for (int i = 1; i <= n;)
        // {
        //     if(vis[i] == 0){
        //         while(i<= n && vis[i] == 0){
        //             i++;
        //         }
        //         cnt++;
        //     }else{
        //         i++;
        //     }
        // }
        cout<<pre[cnt]<<"\n";
    }
    
    return 0;
}