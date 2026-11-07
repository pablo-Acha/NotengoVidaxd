#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

void dfs(ll x,ll p, vll &pre,vll &val ,vll &sum, vll &nivel,vector<vll> &grafo, vector<vll> &grafo2){
    
    for(auto xi:grafo[x]){
        if(xi == p)continue;
        grafo2[x].push_back(xi);
        dfs(xi,x,pre,val,sum,nivel,grafo,grafo2);
        pre[x] += pre[xi];
        sum[x] += sum[xi]+pre[xi];
        nivel[x] = max(nivel[x],nivel[xi]);
    }
    pre[x] +=val[x]; 
    nivel[x] += 1;
}


void dfs2(ll x,ll p, vll &pre,vll &val ,vll &sum, vll &nivel,vll &res,vector<vll> &grafo){
    ll cnt = 0;
    ll ni =0;
    ll ans =0;
    for(auto xi:grafo[x]){
        dfs2(xi,x,pre,val,sum,nivel,res,grafo);
        ans = max(sum[x]-sum[xi]+res[xi],ans);
    }
    vll prefix(grafo[x].size()),sufix(grafo[x].size());
    for (int i = 1; i < grafo[x].size(); i++)
    {
        prefix[i] = max(nivel[grafo[x][i-1]],prefix[i-1]); 
        
    }
    for (int i = grafo[x].size()-2; i >=0; i--)
    {
        sufix[i] = max(nivel[grafo[x][i+1]],sufix[i+1]); 
    }
    for (int i = 0; i < grafo[x].size(); i++)
    {
        ans = max(sum[x]+(max(prefix[i],sufix[i])*pre[grafo[x][i]]),ans);
    }
    

    res[x]= ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vector<vll> grafo(n);
        vll pref(n);
        vll sum(n);
        vll nivel(n);
        vll res(n);
        for (int i = 0; i < n-1; i++)
        {
            ll a,b;cin>>a>>b;
            a--,b--;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }
        vector<vll> grafo2(n);
        dfs(0,0,pref,arr,sum,nivel,grafo,grafo2);
        // for(auto h:sum)cout<<h<<" ";cout<<"\n";
        dfs2(0,0,pref,arr,sum,nivel,res,grafo2);
        for (int i = 0; i < n; i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}