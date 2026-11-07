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
    vector<pll> arr(n);
    for(auto &[a,b]:arr)cin>>a>>b;
    ll left = -1e12;
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        
        if(arr[i].first-arr[i].second>left)
        {
            left = arr[i].first;
            res++;
            continue;
        }
        if(i == n-1 || arr[i].first+arr[i].second<arr[i+1].first){
            left = arr[i].first+arr[i].second;
            res++;
            continue;
        }
        left = arr[i].first;
    }
    cout<<res<<"\n";

    return 0;
}