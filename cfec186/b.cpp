#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll fun(ll x,ll y){
    ll res = 0;
    ll it = 1;
    ll i = 0;
    while (x>=0 && y>=0)
    {
        if(i &1){
            if(x-it<0)break;
            x-=it;
        }else{
            if(y-it<0)break;
            y-=it;
        }
        i++;
        it*=2;
        res++;
    }
    return res;
}

int main(){
    int t;cin>>t;
    while(t--){
        ll a,b;cin>>a>>b;
        ll res = max(fun(a,b),fun(b,a));
        cout<<res<<endl;
    }
}