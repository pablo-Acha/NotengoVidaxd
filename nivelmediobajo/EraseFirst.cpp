#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--) {
        ll n;cin>>n;
        string s;cin>>s;
        set<char> st;
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            if(st.find(s[i]) == st.end()){
                res+= n-i;
                st.insert(s[i]);
            }
        }
        cout<<res<<"\n";
        
    }
}