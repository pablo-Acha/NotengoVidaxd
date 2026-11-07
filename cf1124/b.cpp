#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

ll tranform(ll n){

    for (int i = 0; i < 1000; i++)
    {        
        ll nuevo = 0;
        while(n){
            ll x = n%10;
            n/=10;
            nuevo+= x*x;
        }
        n = nuevo;
    }
    return n;
}

ll gauss(ll n){
    if(n == 0)return 0;
    return (n*(n-1))/2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        for (int i = 0; i < n; i++)
        {
            arr[i] = tranform(arr[i]);
        }
        map<ll,ll> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        ll res = 0;
        for(auto [k,v]:mp){
            res+= gauss(v);
        }
        cout<<res<<"\n";
    }

    return 0;
}