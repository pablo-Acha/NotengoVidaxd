#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

ll fun(ll n,ll b){
    
    ll j = 1;
    ll res = 0;
    while(n>=(1LL<<j)){
        res += (n/(1LL<<j))-((b-1)/(1LL<<j));
        j++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k;
    // cout<<fun(10,4)<<"\n";
    while(cin>>n){
        cin>>k;
        ll r = n-k;
        ll up = fun(n,max(r,k)+1);
        ll down = fun(min(r,k),1);
        if(up >down){
            cout<<"0\n";
        }else{
            cout<<"1\n";
        }

    }

    return 0;
}