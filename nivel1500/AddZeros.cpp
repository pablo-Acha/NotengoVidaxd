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
        vector<pll> arr(n);
        for (int i = 0; i < n; i++)
        {
            auto &[p,s] = arr[i];
            cin>>p;
            p+= i+1;
            s = i;
        }
        sort(all(arr));
        set<ll> st;
        st.insert(arr.size()+1);
        for (int i = 0; i < n; i++)
        {
            auto &[p,s] = arr[i];
            if(st.find(p) != st.end()){
                st.insert(p+s);
            }
        }
        ll res = *prev(st.end());
        cout<<res-1<<"\n";
    }

    return 0;
}