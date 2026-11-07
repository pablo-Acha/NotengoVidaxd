#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
ll guas(ll n){return n*(n+1) /2;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<vector<pll>> grafo(n+1);
        vll val(n+1,-1);
        for (int i = 0; i < n-1; i++)
        {
            ll a,b;cin>>a>>b;
            grafo[a].push_back({b,i});
            grafo[b].push_back({a,i});
        }
        stack<pll> st;
        st.emplace(1,-1);
        val[1] = 1;
        while(!st.empty()){
            auto [x,ix] = st.top();
            st.pop();
            for(auto [vi,ind]:grafo[x]){
                if(val[vi] != -1)continue;
                ll aux = val[x];
                if(ind<ix)aux++;
                val[vi] = aux;
                st.emplace(vi,ind);
            }
        }

        ll mx = *max_element(val.begin(),val.end());
        cout<<mx<<"\n";
    }
    return 0;
}