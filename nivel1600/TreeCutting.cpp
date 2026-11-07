#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

void dfs(vector<vll> &g,vll &tam ,ll x, ll p,ll mid, ll &k)
{
    for(auto ni:g[x]){
        if(ni == p)continue;
        dfs(g,tam,ni,x,mid,k);
        if(k >0){
            if(tam[ni] < mid)tam[x]  += tam[ni];
            else if(tam[ni] >= mid)k--;
        }else{
            tam[x] += tam[ni];
        }
    }
    tam[x]++;
}



bool fun(vector<vll> &g, ll k, ll mid){
    ll n= g.size();
    vll tam(n);
    dfs(g,tam,0,0,mid,k);
    // cout<<mid<<": ";
    // for(auto x:tam){
    //     cout<<x<<" ";
    // }
    
    // cout<<"\n";
    bool f= 1;
    for(auto x:tam){
        if(x <mid)f = 0;break;
    }
    
    return k == 0&& f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        vector<vll> g(n);
        for (int i = 0; i < n-1; i++)
        {
            ll a,b;cin>>a>>b;
            a--,b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        ll l = 1, r = n, mid;
        while(l<=r){
            mid = (l+r)/2;
            if(fun(g,k,mid)){
                l = mid+1;
            }else{
                r =mid-1;
            }
        }
        //r
        cout<<r<<"\n";
    }


    

    return 0;
}