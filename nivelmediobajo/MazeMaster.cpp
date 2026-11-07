#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;
ll X[]  ={-1,0,1,0};
ll Y[]  ={0,-1,0,1};

ll f(vector<string> &arr,ll h,ll w, ll x,ll y){
    vector<vll> vis(h,vector<ll>(w));
    queue<pair<ll,ll>> qu;
    qu.emplace(y,x);
    vis[y][x] = 1;
    ll mx = 1;
    while(!qu.empty()){
        auto [yy,xx] = qu.front();
        qu.pop();
        for (int i = 0; i < 4; i++)
        {
            ll xp = xx+X[i];
            ll yp = yy+Y[i];
            if(yp<0 || yp>=h || xp<0 || xp>=w || arr[yp][xp] == '#' || vis[yp][xp])continue;
            vis[yp][xp] = vis[yy][xx]+1;
            mx = max(vis[yp][xp],mx);
            qu.emplace(yp,xp);
        }
    }
    return mx-1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll h,w;cin>>h>>w;
    vector<string> arr(h);
    for (int i = 0; i < h; i++)
    {
        cin>>arr[i];
    }
    ll res = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if(arr[i][j] == '.'){
                res = max(f(arr,h,w,j,i),res);
            }
        }
        
    }
    cout<<res<<"\n";
    return 0;
}