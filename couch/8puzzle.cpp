#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()
vll X = {-1, 0 , 1 ,0};
vll Y = {0, -1 , 0 ,1};
struct Estado{
    vector<vector<ll>> g;
    ll dist;
    ll x;
    ll y;
};




int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    vector<vll> grid(4,vll(4));
    ll x = 0;
    ll y = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin>>grid[i][j];
            if(grid[i][j] == 0){x = j,y = i;}
        }   
    }
    set<vector<vll>> st;
    vector<vll> res(4,vll(4));
    ll cnt = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            res[i][j] = cnt;
            cnt++;
        }    
    }
    res[3][3] = 0;
    queue<Estado> qu;
    qu.push({grid,0,x,y});
    ll sum = 0;
    st.insert(grid);
    while (!qu.empty())
    {
        Estado  a =qu.front();
        qu.pop();
        if( a.g == res){
            sum = a.dist;
            break;
        }
        if(a.dist == 45){
            continue;
        }
        for (int i = 0; i < 4; i++)
        {
            ll nx = a.x+X[i];
            ll ny = a.y+Y[i];
            if(nx>=0 && nx<4 && ny>=0 && ny<4){
                swap(a.g[a.y][a.x], a.g[ny][nx]);
                if(st.find(a.g) != st.end() ){
                    swap(a.g[a.y][a.x], a.g[ny][nx]);
                    continue;
                }
                st.insert(a.g);
                Estado nue = {a.g,a.dist+1,nx,ny};
                qu.push(nue);
                swap(a.g[a.y][a.x], a.g[ny][nx]);
            }
        }
         
    }
    cout<<sum<<"\n";

    return 0;
}