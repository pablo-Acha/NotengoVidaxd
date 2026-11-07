#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<ll,ll> pii;
typedef  pair<ll,ll> pll;
typedef  vector<ll> vi;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;cin>>n>>m;
    ll cnt = __builtin_popcountll(n);
    // cout<<cnt<<"\n";
    if(cnt>=m){
        ll res = n;

        if(m!=cnt)for (ll i = 0; i <= 62; i++)
        {
            if((res>>i) &1LL){
                res-= 1LL<<i;
                cnt--;
            }
            if(m == cnt)break;
        }
        // cout<<res<<"\n";
        ll aux2 = 0;
        for (ll i = 0; i <= 62; i++)
        {
            if(((res>>i) &1LL) && (res>>(i+1LL))%2 == 0){
                res -= 1LL<<i;
                res += 1LL<<(i+1LL);
                for (ll j = i; j >=0; j--)
                {
                    aux2 = aux2+ ((res>>j) &1LL);
                }                
                res = (res>>i)<<i;
                for (ll j = 0; j <aux2; j++)
                {
                    res += 1LL<<j;
                }
                
                break;
            }
        }
        cout<<res<<"\n";

    }else{
        ll res = n;
        for (ll i = 0; i <= 62; i++)
        {
            if(!((res>>i) &1LL)){
                res+= 1LL<<i;
                cnt++;
            }
            if(cnt== m)break;
        }
        cout<<res<<"\n";
    }
    return 0;
}