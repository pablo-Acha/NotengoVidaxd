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
        set<pll> st;
        for (int i = 0; i < n; i++)
        {
            ll a;cin>>a;
            st.emplace(a,i+1);
        }
        ll mn = 0;
        ll nxt = n+1;
        vll res;
        for(auto &[p,s]:st){
            
            if(s>mn){
                mn = s;
                res.push_back(p);
            }else{
                st.emplace(p+1,nxt);
                nxt++;
            }   
        }
        for(auto x:res)cout<<x<<" ";
        cout<<"\n";
    }

    return 0;
}