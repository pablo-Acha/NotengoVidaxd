#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()


bool dfs(ll inicio, vector<vll>& grafo, vll& vis) {
    stack<ll> st;

    st.push(inicio);
    vis[inicio] = 1;

    while (!st.empty()) {
        ll u = st.top();
        st.pop();
        for (auto v : grafo[u]) {
            if(vis[v] == vis[u]) return false;
            if(vis[v])continue;       
            vis[v] = 3-vis[u];
            st.push(v);
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;cin>>n>>m;
    vector<vll> arr(n+1);
    vll vis(n+1);
    for (int i = 0; i < m; i++)
    {
        ll a,b;cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    bool f =1;
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i] && !dfs(i,arr,vis))
        {
            // cout<<i<<"\n";
            f = 0;
            break;
        }
    }
    if(!f)cout<<"IMPOSSIBLE\n";
    else {for (int i = 1; i <= n; i++)cout<<vis[i]<<" ";cout<<"\n";}     

    return 0;
}

