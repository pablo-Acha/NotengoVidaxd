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
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll mn = 1e18, mx = -1;
        ll res= 0;
        for (int i = 0; i < n; i++)
        {
            res ^=arr[i];
            mn = min(arr[i],mn);
            mx = max(arr[i],mx);
        }
        ll aux = 0;
            // cout<<mx<<" "<<mn<<"-----";

        for (ll i =  34; i >= 0; i--)
        {
            ll top = (1LL<<(i+1))-1; 
            if(((mx>>i)&1LL) && !(((mn>>i)&1LL)))
            {
                aux+= top;
                break;
            }
            aux+= ((mx>>i)&1LL) || (((mn>>i)&1LL))?1LL<<i:0;
        }
        // cout<<"\n";
        res = max(aux,res);
        cout<<res<<"\n";
    }

    return 0;
}