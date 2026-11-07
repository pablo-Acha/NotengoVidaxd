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
    vll pre(100010);
    pre[0] = 1;
    for (int i = 1; i < 100010; i++)
    {
        pre[i] = (pre[i-1]*2)%MOD;
    }
    
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll brr(n);for(auto &a:brr)cin>>a;
        vector<pair<ll,ll>> aind(n);
        vector<pair<ll,ll>> bind(n);
        pair<ll,ll> amx = {arr[0],0},bmx = {brr[0],0};
        aind[0] = amx;
        bind[0] = bmx;
        for (int i = 1; i < n; i++)
        {
            
            if(arr[i]>amx.first){
                amx = {arr[i],i};
            }
            if(brr[i]>bmx.first){
                bmx = {brr[i],i};
            }
            aind[i] = amx;
            bind[i] = bmx;
        }
        vll res(n);
        for (int i = 0; i < n; i++)
        {
            if(aind[i].first > bind[i].first){
                ll a = (pre[aind[i].first]+ pre[brr[i-aind[i].second]])%MOD;
                res[i] = a; 
            }else if(aind[i].first < bind[i].first){
                ll b = (pre[bind[i].first]+ pre[arr[i-bind[i].second]])%MOD;
                res[i] = b;
            }else {
                if(brr[i-aind[i].second]>arr[i-bind[i].second]){
                    ll a = (pre[aind[i].first]+ pre[brr[i-aind[i].second]])%MOD;
                    res[i] = a;
                }else{
                    ll b = (pre[bind[i].first]+ pre[arr[i-bind[i].second]])%MOD;
                    res[i] = b;
                }
            }
        }
        for(auto a:res)
        {
            cout<<a<<" ";
        }
        cout<<"\n";
    }   
    
    return 0;
}