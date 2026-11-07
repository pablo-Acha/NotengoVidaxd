#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<string> vs(n);
        for (int i = 0; i < n; i++)
        {   
            cin>>vs[i];
        }
        vector<vll> grafo(n);
        vll p(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if(vs[i][j] == '0')continue;
                grafo[i].push_back(j);
            }
        }
        for(auto v:grafo){
            for(auto a:v){
                p[a]++;
            }
        }
        
        priority_queue<ll> pq;
        vll vis(n);
        for (int i = 0; i < n; i++)
        {
            if(p[i] == 0){
                vis[i] = 1;
                pq.push(i);
            }
        }

        while(!pq.empty()){
            ll x = pq.top();
            pq.pop();
            cout<<x+1<<" ";
            for(auto ni: grafo[x]){
                if(p[ni] == 0)continue;
                p[ni]--;
                if(p[ni] == 0){
                    pq.push(ni);
                    vis[ni] = 1;
                }
            }     
        }
        cout<<"\n";
    }

    return 0;
}