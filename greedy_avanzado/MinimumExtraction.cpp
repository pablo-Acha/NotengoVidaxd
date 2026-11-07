#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll gaus(ll n){return n*(n+1) /2;}
bool f(ll mid,ll k ,ll x){
    ll res = 0;
    
    if(mid<=k){
        res += gaus(mid);
    }else{
        res +=gaus(k);
        if(res>=x)return false;
        ll aux = gaus(k-1)-gaus((k*2 -1)-mid);
        ll aux1 = 1e18-res;
        res += min(aux1,aux);
    }
    return res<x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr;
        set<ll> st;
        ll ant = 0;
        ll mx = -1e9;
        ll h = 0;

        for (int i = 0; i < n; i++)
        {
            ll a;cin>>a;
            arr.push_back(a);
        }
        sort(arr.begin(),arr.end());
        for (int i = 0; i < n; i++)
        {
            ll a = arr[i];
            a -= ant;
            mx = max(a,mx);
            ant +=a;
            // cout<<mx<<"\n";
            
        }
        
        
        cout<<mx<<"\n";
    }   
       
    return 0;
}