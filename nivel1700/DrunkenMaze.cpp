#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

ll dy[] = {0LL,-1LL,0LL,1LL};
ll dx[] = {-1LL,0LL,1LL,0LL};
ll Dy[] = {0LL,-2LL,0LL,2LL};
ll Dx[] = {-2LL,0LL,2LL,0LL};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;cin>>n>>m;
    vector<string> vs(n);for(auto &x:vs)cin>>x;
    pll ini;
    pll fn;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(vs[i][j] == 'S'){
                ini = {i,j};
            } 
            if(vs[i][j] == 'T'){
                fn = {i,j};
                vs[i][j] = '.';
            }
        }
    }
    
    priority_queue<tuple<ll,pair<ll,ll>,pair<ll,ll>>, vector<tuple<ll,pair<ll,ll>,pair<ll,ll>>>, greater<tuple<ll,pair<ll,ll>,pair<ll,ll>>>> q;
    q.push({0,{0,0},ini});
    vector<vector<ll>> vis(n,vector<ll>(m,1e9));
    bool f = 0;
    // vis[ini.first][ini.second] = 0;
    while(!q.empty()){
        auto [dist,v,pos] = q.top();
        q.pop();
        auto [y,x] = pos;
        auto [cant,dir] = v;
        if(vis[y][x] <dist)continue;
        vis[y][x] = dist;
        if(pos == fn){f= 1;break;}
        for (int i = 0; i < 4; i++)
        {
            ll nx = x+dx[i];
            ll ny = y+dy[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n && vs[ny][nx] != '#')
            {
                pll aux = {0,i};
                ll add = 0;

                if(cant == 3 && dir == i){
                    aux = {2,i};
                    add = 3;
                }else{
                    if(i == dir){
                        aux = {cant+1,i};
                    }else{
                        aux = {1,i};
                    }
                    add = 1;
                }
                if(dist+add<=vis[ny][nx]){
                    q.push({dist+add,aux,{ny,nx}});
                }
            }     
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if(vis[i][j] == 1e18)cout<<-1<<" ";
    //         else
    //         cout<<vis[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    
    cout<<(f?vis[fn.first][fn.second]:-1)<<"\n";

    return 0;
}
