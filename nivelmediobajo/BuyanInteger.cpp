#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll gaus(ll n){
    return (n*(n+1))/2;
}
bool f(ll x, ll p){
    if((x == 1 && !(p&1)) || (x == 2 &&(p&1))){
        return 1;
    }
    return 0;
}

ll coll(ll n ){
    ll res = 0;
    if(n == 0)return 1;
    if(n&1){
        res= (n*3)+1;
    }else{
        res = n/2;
    }   
    return res;
}
ll d(ll n){
    ll res = 0;
    while(n){
        res++;
        n/=10;
    }
    return res;
}
ll f1(ll mid,ll a,ll b){
    return a*mid + b*d(mid);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a,b,x;cin>>a>>b>>x;
    ll l = 1, r = 1e9;
    ll mid;
    while(l<=r){
        mid = l + (r - l) / 2;
        if(x>=f1(mid,a,b)){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    cout<<r<<"\n";
    return 0;
}