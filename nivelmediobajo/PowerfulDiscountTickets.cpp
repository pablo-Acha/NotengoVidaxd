#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;cin>>n>>m;
    priority_queue<ll> pq;
    for (ll i = 0,a; i < n; i++)
    {
        cin>>a;
        pq.push(a);
    }
    while(m){
        auto a = pq.top();
        pq.pop();
        a = a/2;
        m--;
        pq.push(a);
    }
    ll res = 0;
    while(!pq.empty()){
        res+= pq.top();
        pq.pop();
    }
    cout<<res<<"\n";
    return 0;
}