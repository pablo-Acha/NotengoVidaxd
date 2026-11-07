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
        ll n,m;cin>>n>>m;
        vector<ll> arr(n+1);
        iota(all(arr),0);
        // for(auto x:arr)cout<<x<<" ";
        // cout<<"\n";
        for (int i = 0; i < m; i++)
        {
            ll a,b;cin>>a>>b;
            arr[a]--;
            arr[b]++;
        }
        bool f = 1;
        map<ll,ll> mp;
        for (int i = 1; i <=n; i++)
        {
            if(mp.find(arr[i])!=mp.end() || arr[i]<1 || arr[i]>n){
                f = 0;
                break;
            }else{
                mp[arr[i]] = i;
            }
        }
        if(f){
            cout<<"YES\n";
            for(auto [v,x]:mp){
                cout<<x<<" ";
            }
            cout<<"\n";
        }else{
            cout<<"NO\n";
        }
    }
    

    return 0;
}