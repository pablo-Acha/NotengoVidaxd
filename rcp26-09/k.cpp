#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

vll dijstra(ll s, ll d,vector<vector<pll>> &grafo, set<ll> el, ll& fin){
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,s});
    ll n= grafo.size();
    vll val(n);
    while(!pq.empty()){
        auto [dist,v] = pq.top();
        val[v] = dist;
        if(v == d)break;
        for(auto [nodo,p]: grafo[v]){
            if(el.find(nodo)!=el.end())continue;
            pq.push({dist+p,nodo});
        }
    }
    ll act = d;
    ll tam= val[d];
    fin = tam;
    vll res;
    res.push_back(d);
    while(act!=s){
        for(auto [nodo,p]:grafo[act]){
            if(val[nodo] == tam-p){
                act= nodo;
                tam-=p;
                res.push_back(nodo);
                break;
            }
        }
    }
    for (int i = 1; i <res.size()-1; i++)
    {
        el.insert(res[i]);
    }
    return res;    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m,k,s,d;cin>>n>>m>>k>>s>>d;
    vector<vector<pll>> grafo(n+1);
    for (int i = 0; i < m; i++)
    {
        // cout<<i<<"\n";
        ll a,b,p;cin>>a>>b>>p;
        grafo[a].push_back({b,p});
        grafo[b].push_back({a,p});
    }
    
    vll res;
    ll dist = 0;
    set<ll> eli;
    for (int i = 0; i < k; i++)
    {
        if(i == k-1)
        {
            res= dijstra(s,d,grafo,eli,dist);
        }else{
            dijstra(s,d,grafo,eli,dist);
        }
    }
    cout<<dist<<"\n";
    for(auto x:res){
        cout<<x<<" ";
    }cout<<"\n";
    

    return 0;
}