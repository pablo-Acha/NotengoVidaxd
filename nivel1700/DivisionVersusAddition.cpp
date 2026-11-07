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
        ll n,q;cin>>n>>q;
        vll arr(n+1); 
        for (int i = 1; i <= n; i++)
        {
            cin>>arr[i];
        }
        vll pref(n+1);
        vll prex(n+1);
        for (int i = 1; i <= n; i++)
        {
            if(__builtin_popcountll(arr[i]) == 2 && arr[i]&1){
                pref[i]++;
            }
            pref[i] += pref[i-1];
        }
        for (int i = 1; i <= n; i++)
        {
            // cout<<__lg(arr[i])<<" ";
            prex[i] = prex[i-1] +(__builtin_popcountll(arr[i]/2) >=2) +__lg(arr[i]);
        }
        // cout<<"\n";
        // for(auto x:prex)cout<<x<<" ";cout<<"\n";
        // for(auto x:pref)cout<<x<<" ";cout<<"\n";
        for (int i = 0; i < q; i++)
        {
            ll l,r;cin>>l>>r;
            ll sum = prex[r]-prex[l-1] + (pref[r]-pref[l-1])/2;
            cout<<sum<<"\n";
        }
        
    }

    return 0;
}