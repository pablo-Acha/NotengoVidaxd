#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll x,y;cin>>x>>y;
        ll res = x+y;
        ll mx = 0;
        for (ll i = 60; i >= -1; i--)
        {
            if((res>>i)&1){
                if(mx+(1LL<<i) <= x){
                    mx+= 1LL<<i;
                }
            }
        }
        cout<<res<<" "<<x-mx<<"\n";
    }
    

    return 0;
}