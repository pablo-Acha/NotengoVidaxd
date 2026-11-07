#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
const ll MOD  = 1e9 + 7;
long long restaModular(long long a, long long b) {
    return ((a - b) % MOD + MOD) % MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    vector<pair<ll,ll>> arr(t);
    for(auto &[a,b]:arr){
        cin>>a>>b;
    }
    sort(arr.begin(),arr.end());
    ll mx = 0;
    bool f =0;
    for(auto [a,b]:arr){
        if(b<a){
            f = 1;
            break;
        }
        mx = max(b,mx);
    }
    cout<<(f?"Happy Alex":"Poor Alex")<<"\n";    
    return 0;
}