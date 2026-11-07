#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()


ll dx[] = {1,0,-1,0};
ll dy[] = {0,-1,0,1};

bool dfs(pll nodo,ll n ,vector<vll> &vis, map<pll,vector<pll>> &grafo){
    auto [y,x] = nodo;
    if(y == 1 && x == n-1)return true;
    if(vis[y][x])return false;
    vis[y][x] = 1;
    bool f = 0;
    for(auto ni:grafo[nodo]){
        f |= dfs(ni,n,vis, grafo);
    }
    return f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<string> vs(2);
        for (int i = 0; i < 2; i++)
        {
            cin>>vs[i];
        }
        map<pll,vector<pll>> grafo;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int d = 0; d < 4; d++)
                {
                    ll x = dx[d] + j;   
                    ll y = dy[d] + i;
                    if(y>=0 && y<2 && x>=0 && x<n){
                        if(vs[y][x] == '<'){
                            grafo[{i,j}].push_back({y,x-1});
                        }else{
                            grafo[{i,j}].push_back({y,x+1});
                        }
                    }   
                }                
            }            
        }
        // for(auto [p,v]:grafo){
        //     cout<<p.first<<" "<<p.second<<": ";
        //     for(auto [px,py]:v){
        //         cout<<px<<" "<<py<<"\n";
        //     }
        // }
        vector<vll> vis(2,vll(n));
        bool f= dfs({0,0},n,vis,grafo);
        // for(auto v:vis){
        //     for(auto x:v){
        //         cout<<x<<" ";
        //     }cout<<"\n";
        // }
        cout<<(f?"YES\n":"NO\n");
    }

    return 0;
}