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
        vll arr(n);for(auto &a:arr){cin>>a;a = 2*n-a;}
        
        stack<ll> st;
        st.push(arr[0]);
        ll res = 0;
        ll aux = 0;
        for (int i = 1; i < n; i++)
        {
            if(arr[i]>st.top()){
                arr[i] = 2*n - arr[i];
                if(arr[i]>st.top()){
                    while(!st.empty() && arr[i]>st.top()){
                        st.pop();
                        aux++;
                    }
                }
            }        
            st.push(arr[i]);
            res+= aux;
        }
        cout<<res<<"\n";

    }

    return 0;
}