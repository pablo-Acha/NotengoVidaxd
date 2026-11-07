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
        ll n,l,r;cin>>n>>l>>r;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll iz = 0,der= 0,res = 0;
        vll brr;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]<=l){
                iz++;
                res+= abs(l-arr[i]);
            }else if(arr[i]>=r){
                res+= abs(l-arr[i]);
                der++;
            }else{
                brr.push_back(arr[i]);
            }
        }
        sort(all(brr));
        ll m = brr.size();
        ll p = (r-l)*der;
        ll q = (r-l)*iz;
        if(iz>der){
            
            
        }else{

        }
    }

    return 0;
}