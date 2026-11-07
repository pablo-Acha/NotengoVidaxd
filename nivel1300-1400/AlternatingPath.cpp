#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n) { return n * (n + 1) / 2; }

const ll MOD =998244353;
ll modpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%MOD;
        a = a*a%MOD;
        b >>= 1;
    }
    return res;
}
ll C(int n, int x){
    x = min(x, n - x);

    ll num = 1;
    ll den = 1;

    for(int i = 1; i <= x; i++){
        num = num * (n - x + i) % MOD;
        den = den * i % MOD;
    }

    return num * modpow(den, MOD - 2) % MOD; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        vector<vll> grafo(n);
        vll val(n,-1);
        for (int i = 0; i < m; i++)
        {
            ll a,b;cin>>a>>b;
            a--,b--;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }
        ll res = 0;
        for (ll i = 0; i < n; i++)
        {
            if(val[i] == -1){
                stack<ll> cl;
                cl.push(i);
                ll cnt = 0;
                val[i] = 1;
                bool f =1;
                ll a = 0,b = 0;
                while(!cl.empty()){
                    auto act =cl.top();
                    cl.pop();
                    cnt++;
                    a+= val[act] == 1;
                    b+= val[act] == 0;
                    for(auto ch:grafo[act]){
                        if(val[ch] == -1){
                            val[ch] = val[act]?0:1;
                            cl.push(ch);
                        }else{
                            if(val[ch] == val[act]){
                                f = 0;
                            }
                        }
                    }  
                }
                // cout<<cnt<<"\n";
                if(f ){
                    res += max(a,b);
                }
            }
        }
        cout<<res<<"\n";
        
    }    
    
    return 0;
}