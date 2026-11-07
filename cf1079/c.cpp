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
        ll n,q;cin>>n>>q;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll brr(n);for(auto &a:brr)cin>>a;
        vll pre(n+1);
        for (int i = 0; i < n; i++)
        {
            arr[i] = max(arr[i],brr[i]);
        }
        for (int i = n-1; i >=1; i--)
        {
            if(arr[i]>arr[i-1]){
                arr[i-1] = arr[i];
            }
        }
        pre[1] = arr[0];
        for (int i = 2,j = 1; i <= n; i++,j++)
        {
            pre[i]= pre[i-1]+arr[j];
        }
        for (int i = 0; i < q; i++)
        {
            ll l,r;cin>>l>>r;
            ll res = pre[r]-pre[l-1];
            cout<<res<<" ";
        }
        cout<<rnl;
    }
    
    return 0;
}