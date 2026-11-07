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
        map<ll,ll> mp;
        for (int i = 0; i < n; i++)
        {
            if(arr[i] &1){
                mp[1]++;
            }else if(arr[i]%4 == 0){
                mp[3]++;
            }else{
                mp[2]++;
            }
        }
        ll res = 0;
        for(auto [k,v]:mp){
            res = max(v,res);
        }
        cout<<res<<"\n";
    }

    return 0;
}