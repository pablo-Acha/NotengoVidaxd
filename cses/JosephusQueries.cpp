#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

ll canti(ll n, bool f){
    if(!f){
        return n/2;
    }
    return n/2 +(n&1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        ll p = 1;
        ll salt = 2;
        bool f = 0;
        ll act = 0;
        while (act+canti(n,f)<k)
        {
               
        }
        
        
    }

    return 0;
}