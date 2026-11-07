#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

ll gaus(ll n){
    return (n*(n+1))/2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){

        ll n,m;cin>>n>>m;
        vector<map<ll,ll>> arr(n);
        vll brr(n);
        vll indices(n+m+1,-1);
        map<ll,ll> contar;
        for (int i = 0; i < n; i++)
        {
            ll a;cin>>a;
            brr[i] = a;
            indices[a] = 0;
            arr[i][a] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            ll p,v;cin>>p>>v;
            p--;
            arr[p][brr[p]] += i-indices[brr[p]];
            indices[v] = i;
            brr[p] = v;
            // arr[p][brr[p]] += 0;
        }
        
        for (int i = 0; i < n; i++)
        {
            arr[i][brr[i]] += m+1-indices[brr[i]];
        }
        ll res = 0;
       for (int i = 0; i < n; i++)
        {
            for(auto [k,v]:arr[i]){
                contar[k]+=v;
            }
        }
        for (int i = 0; i < n; i++)
        {
            ll acc= 0;
            for(auto [k,v]:arr[i]){
                acc+= v;
                ll x = m+1-acc;
                ll temp =(x*v*2)+gaus(v-1)-v*(contar[k]-v);
                contar[k]-=v;
                res+= temp;

            }
            // cout<<"---\n";
        }
        cout<<res<<"\n";
    }
    

    return 0;
}