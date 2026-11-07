#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll gaus(ll n){return n*(n+1) /2;}

bool f(ll mid,multimap<ll,vll> &mp){

    for(auto [a,v]:mp){
        for(auto x:v){
            if(mid<=x)return false;
            else mid++;
            
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        multimap<ll,vll> mp;
        for (int i = 0; i < n; i++)
        {
            ll a;cin>>a;
            vll aux(a);
            ll mx = 0;
            for (int j = 0; j < a; j++)
            {
                cin>>aux[j];
                mx = max(aux[j]-j,mx);
            }
            mp.insert({mx,aux});
        }
        // cout<<"--------\n";
        // for(auto [x,v]:mp){
        //     cout<<x.first<<" "<<x.second<<" ";
        //     for(auto a:v){
        //         cout<<a<<" ";
        //     }
        //     cout<<"\n";
        // }
        ll l = 1,r = 1e9+1,mid;
        while(l<=r){
            mid = (l+r)/2;
            if(f(mid,mp)){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        cout<<l<<"\n";
    }

    return 0;
}