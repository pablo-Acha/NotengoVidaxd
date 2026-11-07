#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()
const ll MOD = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        // ll n;cin>>n;
        // vll arr(n);for(auto &a:arr)cin>>a;
        ll n,x;cin>>n>>x;
        ll l,r;
        ll res = 0;
        if((3-x%4)+x<=n){
            l = (x/4+1)%MOD, r = (n/4 +(n%4==3) - l +1)%MOD;
            res  = (res +(l*r)%MOD)%MOD;
        }

        if(((5-x%4)%4)+x<=n){
            l = (x/4 +(x%4>=2))%MOD;
            r = (n/4-(n%4 == 0)-l+1)%MOD;          
            res  = (res +(l*r)%MOD)%MOD;
        }
        cout<<res<<"\n";
    }

    return 0;
}