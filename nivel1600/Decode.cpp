#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

const ll MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        string s;cin>>s;
        stack<ll> unos;
        stack<ll> ceros;
        ll n = s.size();
        vll dp(n+1);
        // dp[0] = 1;
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            if(s[i] == '0'){
                ceros.push(i);
                if(!unos.empty()){
                    ll aux =0; 
                    aux = (dp[unos.top()] +  unos.top()+1)%MOD;
                    res = (res + (aux*(n-i))%MOD)%MOD; 
                    dp[i+1] = aux;
                    unos.pop();
                }
            }else{
                unos.push(i);
                if(!ceros.empty()){
                    ll aux =0; 
                    aux =(dp[ceros.top()]+ceros.top()+1)%MOD;
                    res = (res + (aux*(n-i))%MOD)%MOD; 
                    dp[i+1] = aux;
                    ceros.pop();
                }
            }
        }
        // for(auto x:dp)cout<<x<<" ";cout<<"\n";
        cout<<res<<"\n";
    }

    return 0;
}