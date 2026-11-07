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
    ll aux= n-(n/2);
    ll res = n/2 + n/2 +(aux/3 + (aux%3>0)) + (n&1);
    cout<<res<<"\n";  
    
    return 0;
}