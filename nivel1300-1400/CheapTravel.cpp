#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m,a,b;cin>>n>>m>>a>>b;
    ll res = min((n/m) * m * a, (n/m) *b);
    res+= min(a*(n%m), b);
    cout<<res<<"\n";
    return 0;
}