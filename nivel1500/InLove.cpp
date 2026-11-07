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

    ll q;cin>>q;
    multiset<pll> mt;
    set<pll> st;
    set<pll> st2;
    for (int i = 0; i < q; i++)
    {
        char a;cin>>a;
        ll l,r;cin>>l>>r;
        pll nue = {l,r};
        if(a == '+'){
            st2.insert(nue);
            mt.insert(nue);
            auto p = mt.lower_bound(nue);
            if(p !=mt.begin()){
                p--;
                auto [lp,rp] = *p;
                if(rp>=l){
                    st.insert(*p);
                    st.insert(nue);
                }
            }
            p = mt.lower_bound(nue);
            if(p!= prev(mt.end())){
                p++;
                auto [lp,rp] = *p;
                if(lp<=r){
                    st.insert(*p);
                    st.insert(nue);
                }
            }
        }else{
            st2.erase(nue);
            st.erase(nue);
            mt.erase(nue);
            auto p = mt.lower_bound(nue);
            if(p != mt.begin() && p != mt.end()){
                auto [al,ar] = *p;
                p--;
                auto [lp,rp] = *p;
                if(rp>=al){
                    st.insert({lp,rp});
                    st2.insert({lp,rp});
                    st.insert({al,ar});
                    st2.insert({al,ar});
                }else{
                    st.erase({al,ar});
                    st.erase({lp,rp});
                }
            }
        }
        for(auto [x,y]:st){
            cout<<x<<" "<<y<<"\n";
        }
        cout<<"xxxxxxxx\n";
        for(auto [x,y]:mt){
            cout<<x<<" "<<y<<"\n";
        }
        cout<<(st.size()< st2.size() && mt.size()>1?"YES\n":"NO\n")<<"----------\n";
    }
    

    return 0;
}