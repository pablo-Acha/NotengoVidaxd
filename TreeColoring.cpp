#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    
    while(t--){
        int n;cin>>n;
        vector<vll> grafo(n);
        vll nivel(n);
        vll cant(n+1);
        ll ancho = 0;
        for (int i= 0,a,b; i < n-1; i++)
        {
            cin>>a>>b;
            a--;b--;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }
        queue<ll> q;
        q.push(0);
        nivel[0] = 1;
        cant[1] = 1;
        vll pa(n);
        while(!q.empty()){
            ll x = q.front();
            // cout<<x<<endl;
            q.pop();
            for(auto ni:grafo[x]){
                if(nivel[ni])continue;
                pa[ni] = x;
                nivel[ni] = nivel[x]+1;
                cant[nivel[ni]]++;
                q.push(ni);
            }
        }
        ll mx = -1;
        ll unos = 0;
        for(auto x:cant){
            mx =max(x,mx);
            unos+= x == 1;
        }
        ll mxx = -1;
        for (int i = 0; i < n; i++)
        
        {
            ll siz = (ll)grafo[i].size()-1LL;
            if(i == 0)siz++;
            mxx = max(mxx,siz);
        }
        // cout<<mxx<<endl;
        if(mxx==mx){
            mx++;
        }
        ll nNiveles =*max_element(nivel.begin(),nivel.end());
        // cout<<nNiveles<<" ";
        vector<ll> grupo(n);
        vector<queue<ll>> asignador(nNiveles+1);
        for (int i = 0; i <= nNiveles; i++)
        {
            for (int j = 0; j < mx; j++)
            {
                asignador[i].push(j);
            }
        }
        queue<ll> bfs;
        vll vis(n);
        bfs.push(0);
        vis[0] = 1;
        grupo[0] = mx-1;
        asignador[1].pop();
        while(!bfs.empty()){
            auto x= bfs.front();
            bfs.pop();
            for(auto ni: grafo[x]){
                if(vis[ni])continue;
                vis[ni] = 1;
                ll x = asignador[nivel[ni]-1].front();
                asignador[nivel[ni]-1].pop();
                while(x==grupo[pa[ni]]){
                    asignador[nivel[ni]-1].push(x);
                    x = asignador[nivel[ni]-1].front();
                    asignador[nivel[ni]-1].pop();
                }
                grupo[ni] = x;
            }
        }   
        vector<vll> res(mx);     
        for (int i = 0; i < n; i++)
        {
            res[grupo[i]].push_back(i+1);
        }
        cout<<mx<<"\n";
        for(auto v:res){
            cout<<v.size()<<" ";
            for(auto a:v){
                cout<<a<<" ";
            }
            cout<<"\n";
        }
        
    }
    return 0;
}