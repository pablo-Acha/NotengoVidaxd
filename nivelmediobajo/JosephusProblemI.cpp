#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll gaus(ll n){
    return (n*(n+1))/2;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;cin>>n;
    queue<ll> qu;
    for (int i = 1; i <= n; i++)
    {
        qu.push(i);
    }
    ll i = 1;
    while(!qu.empty()){
        ll x = qu.front();
        qu.pop();
        if(i&1){
            qu.push(x);
        }else{
            cout<<x<<" ";
        }
        i++;
    }
    cout<<"\n";
    
    return 0;
}