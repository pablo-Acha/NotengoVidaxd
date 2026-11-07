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
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll fact;
        for (int i = 0; i < n-1; i++)
        {
            if(arr[i+1]%arr[i]!=0){
                ll aux = gcd(arr[i+1],arr[i]);
                ll p = arr[i]/aux;
                fact.push_back(p);
            }
        }
        
        if(fact.size() == 0){
            cout<<1<<"\n";
            continue;
        }

        ll res = fact[0];
        for(auto a:fact){
            res= lcm(res,a);
        }
        cout<<res<<"\n";
    }
    
    return 0;
}