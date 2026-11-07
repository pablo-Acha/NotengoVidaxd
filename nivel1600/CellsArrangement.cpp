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
        vector<pll> v;
        for (int i = 0; i < n; i++){
            v.push_back({1,i+1});
        }
        for (int i = 1; i < n; i++)
        {
            v.push_back({i+1,n});
        }
        
        sort(all(v));
        // for(auto [x,y]:v)cout<<x<<" "<<y<<"\n";
        ll last = 0,cnt= 0;
        ll w = 0;
        for (int i = 0; i < n/2 +(n&1); i++)
        {
            auto [x,y] = v[i];
            cout<<x<<" "<<y<<"\n";
            last = i;
            cnt++;
            w++;
        }
        last+= (n%2== 0);
        for (int i = last + cnt; i < v.size() && w<n; i+=cnt)
        {
            auto [x,y] = v[i];
            cout<<x<<" "<<y<<"\n";   
            w++;
        }
        // cout<<w<<"--\n";
        while(w<n){
            cout<<w+1<<" "<<w+1<<"\n";
            w++;
        }
        cout<<"\n";
        
    }

    return 0;
}