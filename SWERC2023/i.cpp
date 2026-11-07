#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;

ll gaus(ll n){
    ll num = n / MOD;
    ll dem = n % MOD;
    num += (n - 1) / MOD;
    dem += (n - 1) % MOD;
    return (n * (n + 1)) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;cin>>n>>m;
    ll suma = 0, sumb = 0; 
    vll arr(n);for(auto &a:arr){cin>>a;suma+=a;}
    vll brr(m);for(auto &a:brr){cin>>a;sumb+=a;}
    
    ll A = gaus(min(suma-1,sumb))-gaus(m-1);
    ll B = gaus(min(sumb-1,suma))-gaus(n-1);
    if(A == B){
        cout<<"TIED\n";
    }else if(A>B){
        cout<<"ALICE\n";
    }else{
        cout<<"BOB\n";
    }
    return 0;
}