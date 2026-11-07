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
        ll x,n,m;cin>>x>>n>>m;
        if(n+m>30){
            cout<<"0 0\n";
        }else{
            
            ll res = x, res2= x>>n;
            ll aux = m;
            while(aux){res2 = res2/2 + (res2&1); aux--;}
            if(n == 0)while(m){res = res/2 + (res&1); m--;}
            else res= x>>(m+n);
            
            cout<<res<<" "<<res2<<"\n";
        }
    }

    return 0;
}