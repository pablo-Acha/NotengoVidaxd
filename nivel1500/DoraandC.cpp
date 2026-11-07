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
        ll n,a,b;cin>>n>>a>>b;
        ll g = gcd(a,b);
        vll arr(n);for(auto &a:arr){cin>>a;a = a%g;}
        vll gc(n);
        sort(all(arr));
        for (int i = 0; i < n; i++)
        {
            gc[i] = arr[i];
            gc.push_back(arr[i]+g);
        }

        ll res = 1e9;
        for (int i = 0,j = n-1; i < n; i++,j++)
        {
            res = min(res, gc[j]-gc[i]);
        }
        cout<<res<<"\n";
        
        
    }

    return 0;
}