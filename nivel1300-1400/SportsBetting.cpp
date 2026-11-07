#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        map<ll,ll> mp;
        for (int i = 0; i < n; i++)
        {
            ll a;cin>>a;
            mp[a]++;
        }
        bool f = 0;
        bool fp = 0;
        ll ant = 0;
        for(auto [k,v]:mp)
        {
            if(v>=4){
                f= 1;
                break;
            }
            if(fp){
                if(k!=1+ant){
                    fp = 0;
                }else{
                    ant = k;
                }
                if(fp && v >=2){
                    f = 1;
                    break;
                }
            }
            if(v>=2){
                fp = 1;
                ant = k;
            }
        }
        cout<<(f?"YES\n":"NO\n");
    }
    
    return 0;
}