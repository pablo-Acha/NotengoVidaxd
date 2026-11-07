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
        map<ll,ll> mp;
        for (int i = 0; i < n; i++)
        {
            ll a;cin>>a;
            
            mp[a]++;
        }
        vll res;
        while (!mp.empty()) 
        {
            set<ll> st;
            for (auto it = mp.rbegin(); it != mp.rend(); ++it) 
            {
                res.push_back(it->first);
                
                it->second--;
                
                if (it->second == 0) {
                    st.insert(it->first);
                }
            }
            
            for (auto x : st) {
                mp.erase(x);
            }
        }
        for(auto x:res)cout<<x<<" ";cout<<"\n";
    }

    return 0;
}