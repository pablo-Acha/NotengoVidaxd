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
        multiset<ll> st;
        for (int i = 0; i < n; i++)
        {
            ll a;cin>>a;
            st.insert(a);
        }
        vll res(n);
        ll act = 0;
        bool f =1;
        for (int i = 0; i < n; i++)
        {
            auto p = st.upper_bound(act*-1);
            if(p == st.end()){
                f = 0;
                break;
            }
            act+= *p;
            st.erase(p);
            res[i] = act;
        }
        if(f){
            for (int i = 0; i < n; i++)
            {
                cout<<res[i]<<" ";
            }
            cout<<"\n";
        }else{
            cout<<"-1\n";
        }
        
    }

    return 0;
}