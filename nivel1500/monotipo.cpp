#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()
bool is(ll a, ll b, ll x, ll y){
    return ( a >=x &&  b<=y) || ( a <=x &&  b>=y); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll brr(n);for(auto &a:brr)cin>>a;
        
        vector<pll> aprr(n),bprr(n);
        ll mn = 1e9, mx =0;
        for (int i = 0; i < n; i++)
        {
            mn = min(mn,arr[i]);
            mx = max(mx,arr[i]);
            aprr[i] = {mx,mn};
        }
        mn = 1e9, mx =0;
        ll res = 0;
        for (int i = n-1; i >=0; i--)
        {
            mn = min(mn,brr[i]);
            mx = max(mx,brr[i]);
            bprr[i] = {mx,mn};            
        }  
        for (int i = 0; i < n; i++)
        {
            auto [a,b] = aprr[i];
            auto [x,y] = bprr[i];
            bprr[i] = {max(a,x),min(b,y)}; 
            
        }
        ll l  = 0, r = 0;
        set<pll>st; 
        for (int i = 0; i < n; i++)
        {
            if(!is(r,l,bprr[i].first,bprr[i].second)){
                st.emplace(r,l);
                r = bprr[i].first, l = bprr[i].second;
            }else{
                ll tam= r-l;
                if(tam>bprr[i].first-bprr[i].second){
                    r = bprr[i].first, l = bprr[i].second;
                }
            }
        }
        st.emplace(r,l);
        ll ini = 0;
        for(auto [r,l]:st){
            res+= (l-ini)*(2*n-r+1); 
            ini = l;
        }
        
        cout<<res<<"\n";
        
             
        
    }

    return 0;
}