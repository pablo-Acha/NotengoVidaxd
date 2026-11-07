#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

ll fun(ll a,ll b, ll c){
    return (a^b)  + (b^c) + (a^c);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    
    // cout<<fun(965321865, 375544086, 12551794)<<"\n";

    while(t--){
        ll l,r;cin>>l>>r;
        ll a = 0,b = 0,c = 0;
        ll it = 32;
        while(((l>>it)&1) == ((r>>it)&1)){
            if((r>>it)&1){
                a += 1LL<<it;
                b += 1LL<<it;
                c += 1LL<<it;
            }
            it--;
        }
        a +=1LL<<it; b += 1LL<<it;c += 1LL<<it;
        a--;
        // cout<<a<<" "<<b<<" "<<c<<"\n";

        if(a == l)b+= 1;
        else b = a-1;
        cout<<a<<" "<<b<<" "<<c<<"\n";
        // cout<<fun(a,b,c)<<"\n";
    }

    return 0;
}