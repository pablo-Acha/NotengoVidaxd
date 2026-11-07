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
        string s;cin>>s;
        ll n = s.size();
        ll res = 1;
        vll aux(n+1);
        set<ll> st;
        st.insert(0);
        for (int i = 0; i < s.size();)
        {
            if(s[i] == '0'){
                ll cnt = 0;
                while(i<n &&s[i] == '0'){
                    i++;
                    cnt++;
                }
                if(cnt == 1 && i!=1 && i!=n){st.insert(1);}
                else if(cnt>=3)st.insert(3);
            }else{
                ll cnt = 0;
                while(i<n &&s[i] == '1'){
                    i++;
                    cnt++;
                }
                if(cnt == 1 && i!=1 && i!=n){st.insert(1);}
                else if(cnt>=3)st.insert(3);
            }   

        }
        res = st.size();
        
        cout<<res<<"\n";
        
    }

    return 0;
}