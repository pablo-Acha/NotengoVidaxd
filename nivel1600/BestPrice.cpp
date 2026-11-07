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
        ll n,k;cin>>n>>k;
        vector<pll> arr(n);
        vll brr(n);
        for (int i = 0; i < n; i++)
        {
            auto &[b,a] = arr[i];
            cin>>a;
        }
        for (int i = 0; i < n; i++)
        {
            auto &[b,a] = arr[i];
            cin>>b;
            brr[i] = b;
        }
        sort(all(arr));
        sort(all(brr));
        map<ll,ll> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i].second+1]++;
            mp[arr[i].first+1]--;
        }
        ll acc = 0;
        ll res = 0;
        for(auto [y,v]:mp){
            if(acc<=k){
                ll aux = brr.end()-lower_bound(all(brr),y-1);
                res  = max(res, aux*(y-1));
            }
            acc+= v;
        }
        cout<<res<<"\n";
        
    }

    return 0;
}