#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

bool dfs(ll ni, vll &vis, vll &grafo){
    stack<pll> st;
    st.push({ni,ni});

    while(!st.empty()){
        auto [pa,x] = st.top();
        vis[x] = 1;
        st.pop();
        if(grafo[x] == pa){
            return false;
        }else if(grafo[x] == ni){
            return true;
        }
        st.push({x,grafo[x]});
    }
    return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n+1);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i+1];
        }
        vll vis(n+1);
        ll mn = 1,mx = 0;
        for (int i = 1; i <= n; i++)
        {
            if(!vis[i]){
                mx++;
                mn += dfs(i,vis,arr);
            }   
        }        
        cout<<mn<<" "<<mx<<"\n";
    }

    return 0;
}