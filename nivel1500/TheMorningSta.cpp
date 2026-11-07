#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

ll gaus(ll n){
    if(n<=1)return 0;
    return (n*(n-1))/2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<pll> arr(n);
        map<ll,ll> ver;
        map<ll,ll> hor;
        map<ll,ll> diag1;
        map<ll,ll> diag2;
        for(auto [x,y]:arr){cin>>x>>y;
            ver[y]++;
            hor[x]++;
            diag1[x-y]++;
            diag2[x+y]++;
        }
        // for(auto [k,v]:ver){
        //     cout<<k<<" "<<v<<"\n";
        // }
        // cout<<"---\n";
        // for(auto [k,v]:hor){
        //     cout<<k<<" "<<v<<"\n";
        // }
        // cout<<"---\n";
        // for(auto [k,v]:diag1){
        //     cout<<k<<" "<<v<<"\n";
        // }
        // cout<<"---\n";
        // for(auto [k,v]:diag2){
        //     cout<<k<<" "<<v<<"\n";
        // }
        // cout<<"---\n";
        ll res = 0;
        for(auto [k,v]:ver){
            res+= gaus(v)*2;
        }
        for(auto [k,v]:hor){
            res+= gaus(v)*2;
        }
        for(auto [k,v]:diag1){
            res+= gaus(v)*2;
        }
        for(auto [k,v]:diag2){
            res+= gaus(v)*2;
        }
        cout<<res<<"\n";
    }

    return 0;
}