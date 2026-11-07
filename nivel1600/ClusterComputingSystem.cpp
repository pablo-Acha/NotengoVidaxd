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

    ll n;cin>>n;
    vll arr(n);for(auto &a:arr)cin>>a;
    vll pre(n),suf(n);
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = gcd(arr[i],pre[i-1]);
    }
    suf[n-1] = arr[n-1];
    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = gcd(arr[i],suf[i+1]);
    }
    ll res = 0;
    ll mx = 0;
    for (int i = 0; i < n-1; i++)
    {
        res+= min(pre[i],suf[i]);
    }
    cout<<res<<"\n";

    return 0;
}