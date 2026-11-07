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

    ll n,k;cin>>n>>k;
    vll arr;
    for (int i = 0; i < n; i++)
    {
        ll a,b;cin>>a>>b;
        arr.push_back(b);
        arr.push_back(a-b);
    }
    sort(all(arr),greater<ll>());
    ll res = 0;
    for (int i = 0; i < k; i++)
    {
        res+= arr[i];        
    }
    cout<<res<<"\n";
    

    return 0;
}