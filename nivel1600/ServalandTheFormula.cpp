#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

void comp(ll x, ll y,ll k){
    ll res = (x+k+y+k);
    ll res1 = ((x+k)^(y+k));
    cout<<res<<"="<<res1<<"   :";
}
void bin(ll n) {
    // Para 64 bits (ll)
    cout << std::bitset<32>(n) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll x,y;cin>>x>>y;
        if(x == y)cout<<-1<<"\n";
        else {
            if(y>x)swap(x,y);
            ll cnt = 0;
            ll tmp = x;
            while(tmp){
                cnt++;
                tmp/=2;
            }
            ll mx = 1LL<<cnt;
            ll res = mx-x;
            cout<<res<<"\n";
        }
        
    }

    return 0;
}