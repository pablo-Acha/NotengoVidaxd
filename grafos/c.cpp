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

    ll n,m;cin>>n>>m;
    vector<vll> grafo(n+1);
    vll indegree(n+1);
    for (int i = 0; i < m; i++)
    {
        ll a,b;cin>>a>>b;
        grafo[a].push_back(b);
        indegree[b]++;
    }
    queue<ll> q;
    for (int i = 1; i <= n; i++)
    {
        if(indegree[i] == 0)q.push(i);
    }
    vll topo;
    while(!q.empty())
    {
        auto x = q.front();
        topo.push_back(x);
        q.pop();
        for(auto ni:grafo[x]){
            indegree[ni]--;
            if(indegree[ni] == 0){
                q.push(ni);
            }
        }
    }
    if(topo.size() == n){
        for(auto x:topo)cout<<x<<" ";cout<<"\n";
    }else{
        cout<<"IMPOSSIBLE\n";
    }
    return 0;
}