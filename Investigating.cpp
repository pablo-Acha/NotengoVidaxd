#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        ll n;cin>>n;
        vector<pair<ll,ll>> puntos(n);
        for (int i = 0; i < n; i++)
        {
            cin>>puntos[i].first>>puntos[i].second;
        }
        vll dis(n);
        dis[0] = 0;
        for (int i = 1; i < n; i++)
        {
            auto [a,b] = puntos[i];
            auto [aa,bb] = puntos[i-1];
            dis[i] = max(abs(a-aa),abs(b-bb));
        }
        ll l = 0, r = dis[1];
        ll act = r;
        // cout<<"----\n";
        for (int i = 2; i < n; i++)
        {
            if(i%2==0){
                l = max(act-dis[i],l);
                act = act-dis[i];
            }else{
                r = min(act+dis[i],r);
                act = act+dis[i];
            }
            // cout<<act<<" "<<l<<" "<<r<<"\n";
        }
        if(l+2<=r){
            cout<<r-1<<"\n";
        }else{
            cout<<-1<<"\n";
        }

    return 0;
}