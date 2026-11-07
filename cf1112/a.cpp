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
        if(n&1){
            cout<<"NO\n";
        }else{
            ll mn  = 1e10, mx = 0;
            for (int i = 0,j = 1; i < n; i+=2,j+=2)
            {
                mn = min(arr[i],mn);
                mx = max(arr[j],mx);
            }
            // cout<<mn<<" "<<mkkx<<"\n";
            if(mn-1>mx){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }   
        }
    }

    return 0;
}