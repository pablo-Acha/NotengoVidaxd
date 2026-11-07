#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
// typedef  pair<ll,ll> pii;
typedef  pair<ll,ll> pll;
// typedef  vector<ll> vi;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;    
    while(t--){
        ll s,q;cin>>s>>q;
        vll div;
        for (ll i = 1; i*i <= s; i++)
        {
            if(s%i ==0)
            {
                div.push_back(i);
                if(i*i!=s)div.push_back(s/i);
            }
        }
        div.push_back(0);
        div.push_back(1e18);
        sort(all(div));
        vll altura(div.size());
        vll pre(div.size());
        for (ll i = 1; i < div.size()-1; i++)
        {
            altura[i] =s/div[i];
        }
        altura[0] = 1e18;
        for (ll i = 1; i <div.size()-1; i++)
        {
            pre[i] = pre[i-1]+altura[i]*(div[i]-div[i-1]); 
        }
        ll m = div.size();
        // for(auto x:pre)cout<<x<<" ";cout<<"\n";
        while(q--){
            ll x,y;cin>>x>>y;
            ll pos = upper_bound(all(div),x)-div.begin();
            ll res = pre[pos-1]+altura[pos]*(x-div[pos-1]);
            // cout<<res<<"\n";
            // cout<<pos<<"\n";

            ll pos1 = upper_bound(all(altura),y,greater<ll>())-altura.begin();
            // cout<<pos<<" "<<upper_bound(all(altura),y,greater<ll>())-altura.begin()<<"\n";
            // cout<<altura[pos]<<"\n";
            if(pos1-1>=pos){
                res = x*y;
            }else{
                res= res -pre[pos1-1] + div[pos1-1]*y;
            }
            cout<<res<<"\n";
        }   
        
        
    }


    return 0;
}