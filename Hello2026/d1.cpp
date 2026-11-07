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
        while(!q.empty()){
            ll x = q.front();
            // cout<<x<<endl;
            q.pop();
            for(auto ni:grafo[x]){
                if(nivel[ni])continue;
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
        cout<<mx<<"\n";
    }
    return 0;
}