#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

ll mediana(multiset<pll> &st, pll a, multiset<pll>::iterator &m) {
    if (st.empty()) {
        st.insert(a);
        m = st.begin(); 
        return m->first;      
    }

    if (a >= *m) {
        st.insert(a);
        if (!((st.size() - 1) & 1)) {
            m = std::next(m);
        }
    } else {
        st.insert(a);
        if ((st.size() - 1) & 1) {
            m = std::prev(m);
        }
    }
    
    return m->first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vector<set<pll>> dp(n+1);
        multiset<pll> st;
        auto m = st.begin();
        
        for (int i = 1; i <= n; i++)
        {
            pll nuevo = {arr[i-1],i};
            ll me = mediana(st,nuevo,m);
            if(i&1)dp[i].insert({me,1});    
        }
        // for(auto v:dp){
        //     for(auto x:v){
        //         cout<<x.first<<" ";
        //     }
        // }
        // cout<<"\n";
        
        
        for (int i = 1; i < n; i++)
        {
            multiset<pll> stt;
            for (int j = i+1,h = i; j < n+1; j++,h++)
            {
                pll nuevo = {arr[h],h};
                ll med= mediana(stt,nuevo,m);
                if((h-i+1)&1){
                    auto p = dp[i].upper_bound({med,1e9});
                    if(p == dp[i].begin())continue;
                    p--;
                    if(p->first == med){
                        dp[j].insert({med,p->second+1});
                    }
                }
            }
        }
        ll mx = 0;
        // for (int i = 1; i <= n; i++)
        // {
        //     for(auto [v,x]:dp[i]){
        //         cout<<v<<" "<<x<<"\n";
        //         mx = max(x,mx);
        //     }
        //     cout<<"\n";
        // }
        for(auto [v,x]:dp[n]){
            // cout<<v<<" "<<x<<"\n";
            mx = max(x,mx);
        }
        cout<<mx<<"\n";
    }

    return 0;
}