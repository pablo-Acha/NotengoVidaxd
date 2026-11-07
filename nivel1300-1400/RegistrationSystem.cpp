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
    map<string,ll> mp;
    ll t;cin>>t;
    while(t--){
        string s;cin>>s;
        if(mp.find(s) == mp.end()){
            cout<<"OK\n";
            mp[s] = 1;
        }else{
            cout<<s<<mp[s]<<"\n";
            mp[s]++;
        }
    }
    
    return 0;
}