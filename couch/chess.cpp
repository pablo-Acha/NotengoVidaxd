#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()


void borrar( vector<vll> &grid, set<pair<ll,ll>> &puntos, ll y, ll x){
    for (int i = 0; i < 8; i++)
    {
        if(grid[y][i] == 0){
            puntos.emplace(y,i);
            grid[y][i] = 1;
        }
        if(grid[i][x] == 0){
            puntos.emplace(i,x);
            grid[i][x] = 1;
        }
    }
    ll mn = min(y,x);
    ll yy = y-mn, xx = x-mn, it = 0;
    while(yy<8 && xx<8){
        if(grid[yy][xx] == 0){
            puntos.emplace(yy,xx);
            grid[yy][xx] = 1;
        }
        yy++;
        xx++;
    }
    mn = min(7-x, y);
    yy = y-mn, xx= x+mn;
    while(yy<8 && xx>=0){
        if(grid[yy][xx] == 0){
            puntos.emplace(yy,xx);
            grid[yy][xx] = 1;
        }
        yy++;
        xx--;
    }
    
}

ll backTrack(vector<vll> &grid, ll fila){
    if(fila == 8){
        return 1;
    }
    ll res = 0;
    for (int i = 0; i < 8; i++)
    {
        if(grid[fila][i] == 0){
            set<pair<ll,ll>> puntos;
            borrar(grid, puntos, fila,i);
            res+=backTrack(grid,fila+1);
            for (auto [y,x]:puntos)
            {
                grid[y][x] = 0;
            }     
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vll> grid(8,vll(8));
    for (int i = 0; i < 8; i++)
    {
        string s;cin>>s;
        for (int j = 0; j < 8; j++)
        {
            if(s[j] == '*')grid[i][j]= 1;
        }
    }
    ll res = backTrack(grid,0);
    cout<<res<<"\n";
    return 0;
}