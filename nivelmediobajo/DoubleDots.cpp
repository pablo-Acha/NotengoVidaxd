#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll gaus(ll n){
    return (n*(n+1))/2;
}

vll graf[2001];
set<pair<ll,ll>> res[2001];
void bfs(ll i){
    vll nivel(2001);
    vll vis(2001);
    queue<ll> qu;
    qu.push(i);
    vis[i] = 1;
    while(!qu.empty()){
        auto a = qu.front();
        res[nivel[a]].emplace(min(i,a),max(i,a));
        qu.pop();
        for(auto ni:graf[a]){
            if(vis[ni])continue;
            vis[ni] = 1;
            qu.push(ni);
            nivel[ni] = nivel[a]+1;
        }
    }
    
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,x,y;cin>>n>>x>>y;
    for (int i = 1; i <n; i++)
    {
        graf[i].push_back(i+1);
        graf[i+1].push_back(i);
    }
    graf[x].push_back(y);
    graf[y].push_back(x);
    for (int i = 1; i <= n; i++)
    {
        bfs(i);
    }
    for (int i = 1; i <= n-1; i++)
    {
        cout<<res[i].size()<<"\n";
        // for(auto [a,b]:res[i]){
        //     cout<<a<<" "<<b<<" ";
        // }
        // cout<<"\n";
    }
    
    return 0;
}