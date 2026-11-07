#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

ll gaus(ll n){
    return (n*(n+1))/2;
}

bool f(ll mid, ll k, ll sob){
    ll res = 0;
    if(mid>k){
        res= 2*gaus(k) - gaus(k-(mid%k)-1) -k;
    }else{
        res = gaus(mid);
    }
    return res>=sob;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll x,k;cin>>k>>x;
        ll block = (gaus(k)*2)-k;
        // cout<<block<<"\n";
        if(block<=x){
            cout<<(2*k-1)<<"\n";
        }else{
            ll l = 1, r= (2*k)-1, mid;
            while(l<=r){
                mid = (l+r)/2;
                if(f(mid,k,x)){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
            cout<<l<<"\n";
        }
    }

    return 0;
}