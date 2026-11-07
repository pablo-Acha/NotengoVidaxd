#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

bool fun(vll &arr, ll mx){
    multiset<ll> ms;
    for(auto x:arr)ms.insert(x);
    while(!ms.empty()){
        auto  p = ms.lower_bound(mx);
        if(p != ms.end() && *p == mx)
        {
            mx--;
            ms.erase(p);
        }else{
            p = ms.upper_bound(mx*2);
            if(p != ms.end()){
                mx--;
                ms.erase(p);
            }else{
                // cout<<*p<<"\n";
                return false;
            }
        }
        if(mx == -1)return true;
    }
    return false;   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        
        ll l= 0,r = n-1,mid;
        while(l<=r){
            mid = (l+r)/2;
            if(fun(arr,mid)){
                l= mid+1;
            }else{
                r= mid-1;
            }
        }
        cout<<r+1<<"\n";
    }

    return 0;
}