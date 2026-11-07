#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()
const ll INF = 1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;cin>>n>>m;
    vector<tuple<ll,ll,ll>> aristas(n+1);
    for (int i = 0; i < m; i++)
    {
        ll a,b,w;cin>>a>>b>>w;
        aristas[i] = {a,b,w};
    }
    vll dist(n+1,INF);
    dist[1] = 0;
    bool f =0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            auto [a,b,w] = aristas[j];
            if(dist[a]== INF)continue;
            if(dist[b]>dist[a]+w)dist[b] = dist[a]+w;   
        }
    }
            for (int j = 0; j < m; j++)
        {
            auto [a,b,w] = aristas[j];
            if(dist[a]== INF)continue;
            if(dist[b] != INF && dist[b]>dist[a]+w){f = 1;break;}
            if(dist[b]>dist[a]+w)dist[b] = dist[a]+w;   
        }
    if(f){
        cout<<"NEGATIVE CYCLE\n";
    }else{
        for (int i = 1; i <= n; i++)
        {
            cout<<dist[i]<<" ";
        }        
        cout<<"\n";
    }
    

    return 0;
}