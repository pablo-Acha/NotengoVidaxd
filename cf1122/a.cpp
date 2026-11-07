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
        ll n;cin>>n;
        vll arr(3);for(auto &a:arr)cin>>a;
        ll mn = 1e9;
        for (int i = 0; i < 3; i++)
        {
            mn = min(arr[i],mn);
        }
        ll res = n-mn;
        cout<<res<<"\n";
    }
    

    return 0;
}