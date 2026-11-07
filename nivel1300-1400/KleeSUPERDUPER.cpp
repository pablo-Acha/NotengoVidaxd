#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()


ll gaus(ll x){
    if(x<0)return 0;
    return (x*(x+1))/2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        ll l = 0, r= n,mid = 0;
        while(l<=r){
            mid = (l+r)/2;
            if(gaus(mid) + k*(mid+1)<= gaus(n-1)-gaus(mid)+k*(n-mid-1)){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        // cout<<r<<"\n";
        if(r == n-1){
            ll res= abs((gaus(r) + k*(r+1))- (gaus(n-1)-gaus(r)+k*(n-r-1)));
            cout<<res<<"\n";
        }else{
            ll res= abs((gaus(r) + k*(r+1))- (gaus(n-1)-gaus(r)+k*(n-r-1)));
            // cout<<(gaus(r) + k*(r+1))<<" "<< (gaus(n-1)-gaus(r)+k*(n-r-1))<<"\n";
            res = min(res, abs((gaus(r+1) + k*(r+2))- (gaus(n-1)-gaus(r+1)+k*(n-r-2))));
            // cout<<(gaus(r+1) + k*(r+2))<<" "<< (gaus(n-1)-gaus(r+1)+k*(n-r-2))<<"\n";
            // cout<<(gaus(r+1) + k*(r+2))<<"\n";
            cout<<res<<"\n";
        }
    }
    

    return 0;
}