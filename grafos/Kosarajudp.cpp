#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

void dfs(ll x, vector<vll>& grafo, vll& vis, vll& topo){
    stack<pll> st;
    st.push({x,0});
    vis[x] = 1;
    while (!st.empty())
    {
        auto &[ni,ind] = st.top();
        if(grafo[ni].size() == ind){
            st.pop();
            topo.push_back(ni);
        }else{
            ll y = grafo[ni][ind];
            if(!vis[y]){
                vis[y] = 1;
                st.push({y,0});
            }
            ind++;
        }
    }
    
}

void dfs2(ll x, vector<vll>& grafo, vll& vis,vll& grupo, ll cnt){
    stack<pll> st;
    st.push({x,0});
    vis[x] = 1;
    grupo[x] = cnt;
    while (!st.empty())
    {
        auto &[ni,ind] = st.top();
        if(grafo[ni].size() == ind){
            st.pop();
        }else{
            ll y = grafo[ni][ind];
            if(!vis[y]){
                vis[y] = 1;
                st.push({y,0});
                grupo[y] = cnt;
            }
            ind++;
        }
    }
    
}
void dfs3(ll x,vector<vll>& grafo,vector<vll>& fafo,vll& vis, vll& dp, vll& val, vll &pa){
    stack<pll> st;
    st.push({x,0});
    vis[x] = 1;
    while (!st.empty()){
        auto &[ni,ind] = st.top();
        if(grafo[ni].size() == ind){
            st.pop();
            dp[ni] += val[ni]; 
            for(auto x:fafo[ni]){
                dp[x] = max(dp[ni],dp[x]);
            }
        }else{
            ll y = grafo[ni][ind];
            if(!vis[y]){
                vis[y] = 1;
                st.push({y,0});
                pa[y] = ni;
            }
            ind++;
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;cin>>n>>m;
    vll arr(n);for(auto &a:arr)cin>>a;
    vll grupo(n);
    vll vis(n);
    vector<vll> grafo(n),fafo(n);
    vll topo;
    for (int i = 0; i < m; i++)
    {
        ll a,b;cin>>a>>b;
        a--;b--;
        grafo[a].push_back(b);
        fafo[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            dfs(i,grafo,vis,topo);
        }
    }
    reverse(all(topo));
    for(auto &r:vis)r = 0;
    ll cnt= 0;
    for(auto x:topo){
        if(!vis[x]){
            cnt++;
            dfs2(x,fafo,vis,grupo,cnt);
        }
    }
    // for(auto x:grupo)cout<<x<<" ";cout<<"\n";
    vector<vll> grafinho(cnt);
    vector<vll> grafinho2(cnt);
    vll vis1(cnt);
    vll val(cnt);
    for (int i = 0; i < n; i++)
    {
        val[grupo[i]-1]+= arr[i];
    }
    // for(auto r:val)cout<<r<<" ";cout<<"\n";
    for (int i = 0; i < n; i++)
    {
        for(auto x:grafo[i]){
            if(grupo[i]!= grupo[x]){
                grafinho[grupo[i]-1].push_back(grupo[x]-1);
            }
        }
    }
    for (int i = 0; i < grafinho.size(); i++)
    {
        sort(all(grafinho[i]));
        grafinho[i].erase(unique(all(grafinho[i])),grafinho[i].end());
    }
    for (int i = 0; i < grafinho.size(); i++)
    {
        for(auto x:grafinho[i]){
            grafinho2[x].push_back(i);
        }
    }
    
    vll dp(cnt);
    vll pa(cnt);
    for (int i = 0; i < cnt; i++){
        if(!vis1[i]){
            dfs3(i,grafinho,grafinho2,vis1,dp,val,pa);
        }
    }
    ll res = 0;
    for (int i = 0; i < cnt; i++){
        res  = max(dp[i],res);
    }
    cout<<res<<"\n";
    
    
    

    return 0;
}