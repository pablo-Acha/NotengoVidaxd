#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

long long integer_sqrt(long long n) {
    if (n <= 1) return n;
    long long left = 1, right = n, ans = 0;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (mid <= n / mid) { 
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll brr(n);for(auto &a:brr)cin>>a;
        map<ll,ll> mp;
        for (int i = 0; i < n; i++){
            for (int j = arr[i]-brr[i]; j <= arr[i]+brr[i]; j++)
            {
                ll x = abs(j-arr[i]);
                ll y = (brr[i]*brr[i])-(x*x);
                y = integer_sqrt(y);
                if(mp.find(j) == mp.end()){
                    mp[j] = y*2 +1;
                }else{
                    mp[j] = max(y*2 +1,mp[j]);
                }
            }
        }
        ll res = 0;
        for(auto [k,v]:mp){
            // cout<<k<<" "<<v<<"\n";
            res+= v;
        }
        cout<<res<<"\n";
        
    }

    return 0;
}