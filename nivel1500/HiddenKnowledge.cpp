#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

ll f(ll n,ll top,ll l, ll r, vll& arr){
    set<ll> st;
    map<ll,ll> mp;
    ll res = 0;
    ll mx = 0,mn = 0;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
        mp[arr[i]] = i;
        if(st.size() == top){
            for (int j = mn; j <= i; j++){
                if(j == mp[arr[j]]){
                    mn = j;
                    break;
                }                
            }
        }
        if(st.size()>top){
            st.erase(arr[mn]);
            mx = mn+1;
            for (int j = mx; j <= i; j++)
            {
                if(j == mp[arr[j]]){
                    mn = j;
                    break;
                }                
            }
        }
        // cout<<i<<" "<<mn<<" "<<mx<<"\n";
        // cout<<i<<" "<<mx<<" "<<mn<<"\n";
        if(st.size()==top){
            ll p = i-mn+1;
            ll s = i-mx+1;
            // if(i == 3)cout<<p<<" "<<s<<"\n";
            if(min(r,s)>=max(p,l) ){
                res+= min(r,s)- max(p,l)+1;
            }
        } 
        // cout<<res<<"\n";
    }
    
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n,k,l,r;cin>>n>>k>>l>>r;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll res = f(n,k,l,r,arr);
        cout<<res<<"\n";
    }

    return 0;
}