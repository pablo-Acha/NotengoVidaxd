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
    vector<vll> arr(n,vll(n));
    vector<vll> dp(n,vll(n));
    ll res = 0;
    for(auto &v:arr)for(auto &x:v){cin>>x;res+=x;}
    ll mn = 1e10;
    for (int i = 0; i < n; i++)
    {
        mn = min(mn,arr[n-i-1][i]);
    }
    res-=mn;
    cout<<res<<"\n";

    return 0;
}