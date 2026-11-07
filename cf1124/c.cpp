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
    while(t--)
    {   
        ll n,k;cin>>n>>k;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll l = k-1, r = n-k;
        vll brr;
        ll res = 0;
        // cout<<l<<" "<<r<<"\n";
        for (int i = 0; i < n; i++)
        {
            if(i>=l && i<r){
                res+= arr[i];
            }else{
                brr.push_back(arr[i]);
            }
        }
        ll m = brr.size();
        // cout<<m<<"--\n";
        l = k-1;r = m-k;
        while(l<m){
            res += max(brr[l],brr[r]);
            l++;r--;
        }

        cout<<res<<"\n";
    }

    return 0;
}