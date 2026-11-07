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
        sort(all(arr));
        set<ll> st;
        ll res = 1e10;
        for (int i = 0; i < n-1; i++)
        {
            ll ind = lower_bound(all(arr),arr[i]+arr[i+1])-arr.begin();
            res = min(n-ind +i,res);
            
        }
        
        cout<<res<<"\n";
    }

    return 0;
}