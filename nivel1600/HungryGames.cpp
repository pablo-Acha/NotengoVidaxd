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
        ll n,x;cin>>n>>x;
        vll arr(n+2);
        vll pre(n+2);
        for (int i = 1; i <= n; i++)
        {
            cin>>arr[i];
        }
        
        for (int i = 1; i <= n; i++)
        {
            pre[i] = pre[i-1]+arr[i];
        }
        pre[n+1] = 1e18;
        vll res(n+2);
        // for(auto x:pre)cout<<x<<" ";cout<<"\n";
        for (int i = 1; i <= n; i++)
        {
            ll p = upper_bound(all(pre),x+pre[i-1])-pre.begin()+1;
            // cout<<p<<"\n";
            if(p<=n+1)res[p]+= res[i]+1;
        }
        ll sum = accumulate(all(res),0LL);
        ll r = ((n*(n+1))/2)-sum;
        cout<<r<<"\n";
    }

    return 0;
}