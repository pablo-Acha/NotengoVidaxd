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
    // ll t;cin>>t;
    // while(t--){
        ll n;cin>>n;
        vll arr(n+1);
        for (int i = 1; i <= n; i++)
        {
            cin>>arr[i];
        }
        
        set<pair<ll,ll>> st;
        
        ll val = 0;
        ll ini  = 0, fin = 0;
        bool f= 0;
        ll mn = 0,mx =0;
        for (int i = 0; i <= n && !f; i++)
        {
            val += arr[i];
            mn = min(val,mn);
            mx = max(val,mx);
            for (int j = (((val-mx)/n)-1)*n; j <= (((val-mn)/n)+1)*n  && !st.empty(); j+=n)
            {
                
                auto p = st.lower_bound({val-j,0});
                if(p == st.end())continue;
                auto [v,in] = *p;
                 if(val-j == v){
                    ini = in+1;
                    fin = i;
                    f = 1;
                    break;
                }
            }
            // cout<<"-----\n";
            // for(auto [x,d]:st){
            //     cout<<x<<" "<<d<<"\n";
            // }
            // cout<<"\n";
            st.emplace(val,i);
        }
        // cout<<ini<<" "<<fin<<"\n";
        // if(ini == 1e9+1)ini = 0;
        // for(auto [a,i]:st){
        //         cout<<a<<" "<<i<<"\n";
        // }
        cout<<fin-ini+1<<"\n";
        for (int i = ini; i <= fin; i++)
        {
            cout<<arr[i]<<"\n";
        }

    // }
    

    return 0;
}