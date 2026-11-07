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
        ll n,k,p,q;cin>>n>>k>>p>>q;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll pref(n+2,0),suf(n+2,0);
        vll X(n),Y(n);
        for (int i = 1; i <= n; i++)
        {
            ll x = arr[i-1]%p;
            ll y = (arr[i-1]%q)%p;
            X[i-1] = x;
            Y[i-1] = y;
            pref[i] = min(x,y) + pref[i-1];
        }
        for (int i = n; i >=1; i--)
        {
            ll x = arr[i-1]%p;
            ll y = (arr[i-1]%q)%p;
            suf[i] = min(x,y) + suf[i+1];
        }
        ll x = 0,y = 0;
        for (int i = 0; i < k; i++)
        {
            x+= arr[i]%p;
            y+= (arr[i]%q)%p;
        }
        ll res = min(x+suf[k+1],y+suf[k+1]);
        // cout<<x<<" "<<y<<"\n";
        for (int i = k+1,j = 0; i <= n+1; i++,j++)
        {
            ll aux = pref[j]+suf[i];
            res = min(res,min(x+aux,y+aux));
            if(i-1 ==n)break;
            x= x-X[j] + X[i-1];
            y= y-Y[j] + Y[i-1];
        }
        cout<<res<<"\n";

    }

    return 0;
}