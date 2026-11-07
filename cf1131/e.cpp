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
    while(t--)
    {    
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll brr(n,1);
        for (int i = 0; i < n; i++)
        {
            if(arr[i] == 0){
                brr[i] = -1;
            }
        }
        vll crr;
        vll res;
        
        ll act = 1;
        // for(auto w:brr)cout<<w<<" ";cout<<"\n";

        for (int i = 0; i < n; i++)
        {
            act *= brr[i];
            if(arr[i] != 0){
                arr[i] *= act;
                crr.push_back(arr[i]);
            }
        }
        for (int i = 0; i < crr.size(); i++)
        {
            res.push_back(abs(crr[i]));
        }
        stack<ll> st;
        ll m = crr.size();
        // for(auto w:crr)cout<<w<<" ";cout<<"\n";
        for (int i = 0; i < m; i++)
        {
            if(crr[i] <0){
                st.push(i);
                if(st.size()>=2){
                    ll x = st.top();
                    st.pop();
                    ll y = st.top();
                    if((x-y)%2 == 0){
                        st.push(x);
                    }else{
                        st.pop();
                    }
                }
            }
        }
        ll r = st.size();
        sort(all(res));
        for (int i = 0; i < r; i++)
        {
            res[i]*=-1;
        }
        // cout<<r<<"\n";
        ll acc = accumulate(all(res),0LL);
        cout<<acc<<"\n";
        
    } 

    return 0;
}