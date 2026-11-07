#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

void dfs(ll nodo, ll p, vector<vll>& grafo, vll& res, vll& val){
    set<ll> st;
    for(auto x:grafo[nodo]){
        if(st.find(val[x]) != st.end() || val[x] == val[nodo]){
            res[val[x]] = 1;
        }else{
            st.insert(val[x]);
        }
        if(x!=p){
            dfs(x,nodo,grafo,res,val);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll val(n);for(auto &a:val)cin>>a;
        vll res(n+1);
        vector<vll> grafo(n);
        for (int i = 0; i < n-1; i++)
        {
            ll a,b;cin>>a>>b;
            a--,b--;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        dfs(0,0,grafo,res,val);
        for (int i = 1; i <= n; i++)
        {
            if(res[i]){
                cout<<"1";
            }else{
                cout<<"0";
            }
        }
        cout<<"\n";
        
    }

    return 0;
}