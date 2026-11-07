#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()
const ll MOD =1e9+7 ; 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<vll> arr(n);
        vll parent(n);
        vll val(n,0);
        stack<ll> st;
        vll hijos(n);
        for (int i = 0; i < n; i++)
        {
            ll a,b;cin>>a>>b;
            if(a == 0){
                st.push(i);
                continue;
            }
            hijos[i] +=2;
            a--;b--;
            arr[i].push_back(a);
            arr[i].push_back(b);
            parent[a]= i;
            parent[b]= i;
        }
        while(!st.empty()){
            ll x = st.top();
            st.pop();
            if(x == 0){val[x] = (val[x]+1)%MOD;continue;}
            hijos[parent[x]]--;
            val[parent[x]]= (val[parent[x]]+val[x])%MOD;
            if(hijos[parent[x]] == 0){
                st.push(parent[x]);
                val[parent[x]]=(val[parent[x]]+4)%MOD;
            }
            // cout<<x<<"| ";
            
        }
        st.push(0);
        while(!st.empty()){
            auto x = st.top();
            st.pop();
            for(auto ni:arr[x]){
                val[ni] = (val[ni] +val[x]+1)%MOD;
                st.push(ni);
            }
        }
        for(auto a:val){
            cout<<a<<" ";
        }
        cout<<"\n";
    }

    return 0;
}