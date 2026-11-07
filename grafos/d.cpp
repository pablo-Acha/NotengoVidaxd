#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

vll parent;
vll tam;
ll mx = 1;
ll comp = 0;
ll find(ll x){
    if(x == parent[x])return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void unite(ll a,ll b){
    ll ra = find(a);
    ll rb = find(b);
    if(ra == rb)return;
    comp--;
    if(tam[ra]<tam[rb])swap(ra,rb);
    tam[ra] += tam[rb]; 
    mx = max(tam[ra],mx);
    parent[rb] = ra;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;cin>>n>>m;
    parent.resize(n);
    tam.resize(n);
    iota(all(parent),0LL);
    for(auto &x:tam)x = 1;
    comp = n;
    for (int i = 0; i < m; i++)
    {
        ll a,b;cin>>a>>b;
        a--,b--;
        unite(a,b);
        cout<<comp<<" "<<mx<<"\n"; 
    }
    
    return 0;
}