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
        // ll n;cin>>n;
        ll x,y,k;cin>>x>>y>>k;
        ll d = y-x;
        ll res = 0;
        ll cnt = 0;
        
        for (int i = x, j= 0; i <= d && j<k; i++,j++)
        {
            res+= d%i;
            cnt++;
            // cout<<cnt<<"\n";
        }
        if(k-cnt>0){
            res += d*(k-cnt); 
        }
        cout<<res<<"\n";
    }

    return 0;
}