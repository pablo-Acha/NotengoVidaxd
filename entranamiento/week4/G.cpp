#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

vector<vector<ll>>islas;

void dfs(ll inicio, vector<vector<ll>> &grafo, vector<bool> &vis){

    stack<ll> pilita;

    pilita.push(inicio);

    vector<ll>isla;
    vis[inicio] = 1;
    while(!pilita.empty()){
        ll actual = pilita.top();
        pilita.pop() ;       
        isla.push_back(actual);
        // if(vis[actual]) continue;
        
        // vis[actual] = true;

        for (ll i = 0; i < grafo[actual].size(); i++)
        {
            ll brochi = grafo[actual][i];
            if(!vis[brochi]){
                vis[brochi] = 1;
                pilita.push(brochi);
            }
        }
        
    }

    islas.push_back(isla);


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    ll n,m; cin>>n>>m;

    vector<vector<ll>> grafo(n);
    for (ll i = 0; i < m; i++)
    {
        ll a,b;cin>>a>>b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    vector<bool>vis(n,false);

    for (ll i = 0; i < n; i++)
    {
        if(!vis[i]){
            dfs(i,grafo,vis);
        }
    }

    set<pair<ll,ll>> orden;

    for (ll i = 0; i < islas.size(); i++)
    {
        orden.insert({islas[i].size(),i});
    }
    
    ll l = 0, r = orden.size()-1;
    ll right = 0;
    ll left = 0;
    vector<pll> res;

    while(orden.size()>1){
        auto [p,i] = *prev(orden.end());
        auto [q,j] = *orden.begin();
        orden.erase(prev(orden.end()));
        orden.erase(orden.begin());
        p--,q--;
        res.push_back({islas[i][p],islas[j][q]});
        if(p>0){
            orden.insert({p,i});
        }
        if(q>0){
            orden.insert({q,j});
        }
    }
    cout<<res.size()<<"\n";
    for(auto [a,b]:res)cout<<a<<" "<<b<<"\n";

    
    
    
    

    return 0;
}