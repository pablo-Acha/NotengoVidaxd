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
        ll sum = accumulate(all(arr),0LL);
        ll mx = sum/2 +(sum&1);
        for (int i = 1; i < n; i++)
        {
            arr[i] +=arr[i-1];
        }
        ll ind = upper_bound(all(arr),mx)-arr.begin();
        ll res = n-ind + mx;
        cout<<res<<"\n";
    }

    return 0;
}