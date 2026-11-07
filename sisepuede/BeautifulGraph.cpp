#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()
ll global1 = 0;
ll global2 = 0;
bool dfs(ll nodo, vll& vis, vector<vll>& grafo){
    global1+= vis[nodo] == 1;
    global2+= vis[nodo] == 2;
    for(auto x:grafo[nodo]){
        if(vis[x] == vis[nodo]){
            return false;
        }else if(vis[x] == 0){
            vis[x] = 3-vis[nodo];
            bool f= dfs(x,vis,grafo);
            if(!f)return false;
        }
    }
    return true;
}
const ll MOD = 998244353;

ll pot(ll base, ll exp){
    ll a = 1;
    for (int i = 0; i < exp; i++)
    {
        a = (a*base)%MOD;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        vector<vll> grafo(n);
        for (int i = 0; i < m; i++)
        {
            ll a,b;cin>>a>>b;
            a--,b--;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }
        vll vis(n);

        ll res = 1;
        bool f = 1;
        for (int i = 0; i < n; i++)
        {
            if(vis[i] == 0){
                global1 = 0;
                global2 = 0;
                vis[i] = 1;
                f = dfs(i,vis,grafo);
                ll aux = (pot(2,global1) + pot(2,global2))%MOD;
                res = (res * aux)%MOD;
            }
            if(!f)break;
        }
        
        if(f){

            cout<<res<<"\n";
        }else{
            cout<<0<<"\n";
        }
    }

    return 0;
}