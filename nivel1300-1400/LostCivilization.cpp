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
        vll arr(n);for(auto &a:arr)cin>>a;
        ll res = 1;
        stack<ll> st;
        st.push(arr[0]);
        for (int i = 1; i < n; i++)
        {
            if(st.top()!= arr[i]-1){
                while(!st.empty() && st.top()!= arr[i]-1){
                    st.pop();
                }
                if(st.empty()){
                    res++;
                }
                st.push(arr[i]);
            }else{
                st.push(arr[i]);
            }
        }
        cout<<res<<"\n";

    }

    return 0;
}