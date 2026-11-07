#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

ll res = 0;

ll dfs(ll x, ll p, vector<vll> &grafo, ll niv){
    if(grafo[x].size() == 0){
        res++;
        // cout<<x<<" 1\n";
    //    cout<<x<<" "<<1<<"\n";
        return 1;
    }
    priority_queue<ll> pq;
    for(auto ni:grafo[x])
    {
        pq.push(dfs(ni,x,grafo,niv+1));
    }
    ll mx = pq.top();
    pq.pop();
    res+= pq.empty()?1:pq.top()+1;
    // cout<<x<<" "<<(pq.empty()?1:pq.top())<<"\n";
    return mx+1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        res = 0;
        vector<vll> grafo(n+1);
        for (int i = 2; i <= n; i++)
        {
            ll a;cin>>a;
            grafo[a].push_back(i);
        }

        dfs(1,0,grafo,0);
        cout<<res<<"\n";
    }

    return 0;
}