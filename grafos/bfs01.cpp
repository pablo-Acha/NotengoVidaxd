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
    vector<vector<pll>> grafo(n);
    for (int i = 0; i < m; i++)
    {
        ll a,b,w;cin>>a>>b>>w;
        a--,b--;
        grafo[a].push_back({w,b});
        grafo[b].push_back({w,a});
    }
    deque<pll> dq;
    dq.push_back({0,0});
    vll dist(n,1e18);
    // dist[0] = 0;
    while(!dq.empty()){
        auto [w,x] = dq.front();
        dq.pop_front();
        if(dist[x]<=w)continue;
        dist[x] = w;
        for(auto [v,ni]:grafo[x]){
            if(v+w<dist[ni]){
                if(v == 0)dq.push_front({v+w,ni});
                else dq.push_back({v+w,ni});
            }
        }
    }
    for(auto x:dist){
        cout<<(x == 1e18?-1:x)<<" ";
    }
    cout<<"\n";

    return 0;
}