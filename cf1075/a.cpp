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
        ll n,h,l;cin>>n>>h>>l;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll mx = max(h,l), mn = min(h,l);
        ll a = 0,b = 0;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]<=mn){
                a++;
            }else if(arr[i]<=mx){
                b++;
            }
        }
        if(a>b){
            ll resi = a-b;
            ll res = b + resi/2;
            cout<<res<<rnl;
        }else{
            cout<<a<<rnl;
        }
        
    }
    
    return 0;
}