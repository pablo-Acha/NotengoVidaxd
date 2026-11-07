#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n) { return n * (n + 1) / 2; }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        map<ll,ll> mp;
        
        for (int i = 0; i < n; i++)
        {
            ll a;cin>>a;
            mp[a]= i;
        }
        ll mx = 0;
        while(!mp.empty()){
            auto [x, ind] = *mp.begin();
            for(auto [k, v] : mp){
                if(gcd(k, x) == 1){
                    mx = max(mx, ind+v+2);
                }
            }
            mp.erase(mp.begin());
        }
        if(mx == 0){
            cout<<"-1\n";
        }else{
            cout<<mx<<"\n";
        }
    }
    
    return 0;
}