#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

void p(ll n){
    while(n){
        cout<<(n&1);
        n/=2;
    }
    cout<<"\n";
}

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;cin>>t;
    while(t--){ 
        ll n,m;cin>>n>>m;
        bool f = 1;
        ll x = 0,y = 0;
        while (!(n>>x&1LL))x++;
        while (!(m>>y&1LL))y++;
        p(n);p(m);
    }

    return 0;
}