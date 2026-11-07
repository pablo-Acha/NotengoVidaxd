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
    if(n&1){
        res= (n*3)+1;
    }else{
        res = n/2;
    }   
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k;cin>>n>>k;
    vll arr(n+2);
    for (int i = 0,a,b; i < k; i++)
    {
        cin>>a>>b;
        arr[a]++;
        arr[b+1]--;
    }
    ll aux = 0;
    vll val(n+2);
    for (int i = 1; i <= n; i++)
    {
        aux += arr[i];
        val[i] = aux;
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        if(val[i] == k){
            res++;
        }
    }
    cout<<res<<"\n";
    
    return 0;
}