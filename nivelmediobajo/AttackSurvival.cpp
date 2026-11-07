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
    ll n,k,q;cin>>n>>k>>q;
    vll arr(n,k);
    for (int i = 0,a; i < q; i++)
    {
        cin>>a;
        a--;
        arr[a]++;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i]-=q;
        if(arr[i]<=0){
            cout<<"No\n";
        }else{
            cout<<"Yes\n";
        }
    }
    
    return 0;
}