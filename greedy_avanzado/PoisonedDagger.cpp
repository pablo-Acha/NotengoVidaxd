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
        ll k,x;cin>>k>>x;
        ll l = 0,r = (k*2) -1,mid;
        while(l<=r){
            mid = l + (r-l)/2;
            if(f(mid,k,x))
            {
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        cout<<min(l,(k*2-1))<<"\n";
    }   
       
    return 0;
}