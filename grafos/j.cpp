#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;cin>>n>>m;
    vll dist(n+1);
    vector<tuple<ll,ll,ll>> aristas(m);
    vll parent(n+1);
    for (int i = 0; i < m; i++)
    {
        auto &[a,b,w] = aristas[i];
        cin>>a>>b>>w;
    }

    for (int i = 0; i < n-1; i++)
    {
        for(auto [a,b,w]:aristas){
            if(dist[b]>dist[a]+w){
                dist[b] = dist[a]+w;
                parent[b] = a;
            }
        }
    }
    vll res;
    ll act = 0;
    for(auto [a,b,w]:aristas){
        if(dist[b]>dist[a]+w){
            dist[b] = dist[a]+w;
            parent[b] = a;
            act = b;
            for (int i = 0; i < n; i++)
            {
                act = parent[act];
            }
            break;
        }
    }
    if(act == 0)cout<<"NO\n";
    else{
        cout<<"YES\n";
        res.push_back(act);
        // cout<<act<<" ";
        ll temp = parent[act];
        while(temp!=act){
            res.push_back(temp);
            temp = parent[temp];
        }
        res.push_back(temp);
        reverse(all(res));
        for(auto x:res)cout<<x<<" ";cout<<"\n";
        // cout<<act<<"\n";
    }
    return 0;
}