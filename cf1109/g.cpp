#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()


ll fun(vll &arr){
    set<ll> st;
    ll n = arr.size();
    vector<vll> brr(n);
    for (int i = 0; i < n; i++)
    {
        if(i+arr[i]+1<n){
            brr[i+arr[i]+1].push_back(arr[i]);
        }
    }

    ll res = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        st.insert(arr[i]);
        for(auto x:brr[i]){
            auto p = st.upper_bound(x);
            if(p == st.begin())continue;
            p--;
            res = max(*p+x,res); 
        }
    }
    return res;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll brr = arr;
        reverse(all(brr));
        ll res = max(fun(brr),fun(arr));
        ll mx = *max_element(all(arr));
        res = max(res,mx);
        cout<<res<<"\n";
    }

    return 0;
}