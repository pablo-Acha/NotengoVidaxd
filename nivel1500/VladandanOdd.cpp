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
    while (t--)
    {
        ll n,k;cin>>n>>k;
        ll top = n;
        ll act = n;
        for (ll i = 0; i < 62; i++)
        {
            ll query = act/2 +((top>>i) &1);
            // cout<<query<<" "<<k<<"\n";
            if(k<=query){
                k = k*2 -1;
                cout<<k*(1LL<<i)<<"\n";
                break;
            }else{
                ll aux =act/2+((top>>i) &1); 
                act -= aux;
                k-= aux;
                if((top>>i) &1){
                    top-= (1LL<<i);
                }
            }
        }
        
    }
       

    return 0;
}