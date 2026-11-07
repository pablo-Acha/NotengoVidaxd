#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;cin>>n>>m;
    ll suma = 0, sumb = 0; 
    vll arr(n);for(auto &a:arr){cin>>a;suma+=(a+1);}
    vll brr(m);for(auto &a:brr){cin>>a;sumb+=(a+1);}
    
    if(suma == sumb){
        cout<<"TIED\n";
    }else if(suma>sumb){
        cout<<"ALICE\n";
    }else{
        cout<<"BOB\n";
    }
    return 0;
}