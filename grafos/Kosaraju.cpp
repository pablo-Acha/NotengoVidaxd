#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

void dfs(ll nodo, vector<vll>& grafo, vll& vis, vll& topo){
    stack<pll> st;
    st.push({nodo,0});
    vis[nodo] = 1;
    while(!st.empty()){
        auto &[ni,ind] = st.top();
        if(ind == grafo[ni].size()){
            topo.push_back(ni);
            st.pop();
        }else{
            if(!vis[grafo[ni][ind]]){
                vis[grafo[ni][ind]] = 1;
                st.push({grafo[ni][ind],0});
            }
            ind++;
        }
    }
}   
void dfs2(ll nodo, vector<vll> &grafo, vll &vis,vll &grupo,ll cnt){
    // cout<<nodo<<"\n";
    stack<pll> st;
    st.push({nodo,0});
    vis[nodo] = 1;
    grupo[nodo] = cnt;
    while (!st.empty())
    {
        auto &[ni,ind] = st.top();
        if(grafo[ni].size() == ind){
            st.pop();
        }else{
            if(!vis[grafo[ni][ind]]){
                vis[grafo[ni][ind]] = 1;
                grupo[grafo[ni][ind]] = cnt;
                st.push({grafo[ni][ind],0});
            }
            ind++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k;cin>>n>>k;
    vector<vll> grafo(n);
    vector<vll> fagro(n);
    for (int i = 0; i < k; i++)
    {
        ll a,b;cin>>a>>b;
        a--,b--;
        grafo[a].push_back(b);
        fagro[b].push_back(a);
    }
    vll vis(n);
    vll vis2(n);
    vll topo;
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            dfs(i,grafo,vis,topo);
        }
    }
    reverse(all(topo));
    // for(auto x:topo)cout<<x<<" ";cout<<"------\n";
    ll cnt = 0;
    vll grupo(n);
    for(auto x:topo){
        if(!vis2[x]){
            cnt++;
            dfs2(x,fagro, vis2, grupo,cnt);
        }
    }
    cout<<cnt<<"\n";
    for(auto x:grupo){
        cout<<x<<" ";
    }
    cout<<"\n";

    return 0;
}