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
    ll n;cin>>n;
    vll val(n);
  
    vector<vll> grafo(n); 
    vector<ll> pa(n);
    for (int i = 0; i < n-1; i++)
    {
        ll a,b;cin>>a>>b;
        a--;b--;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
        pa[a]++;
        pa[b]++;
    }
    queue<ll> qu;
    for (int i = 0; i < n; i++)
    {
        if(pa[i] == 1){
            qu.push(i);
        }
    }
    
    
    for(auto &a:val)cin>>a;
    vll dp(n);
    vll S(n);
    ll lst = -1;
    while (!qu.empty())
    {
        auto a = qu.front();
        lst= a;
        qu.pop();
        S[a] += val[a];
        pa[a] = 0;
        for(auto h:grafo[a]){
            if(pa[h] == 0)continue;
            pa[h]--;
            if(pa[h] == 1)qu.push(h);
            S[h]+= S[a];  
        }        
    }
    // for(auto a:S){
    //     cout<<a<<" ";
    // }
    // cout<<"\n";
    queue<ll> q;
    q.push(lst);
    vll niv(n);
    niv[lst]= 1;
    ll aux = 0;
    while(!q.empty()){
        auto vi = q.front();
        q.pop();
        aux += niv[vi] * val[vi];
        // cout<<aux<<"\n";
        for(auto h :grafo[vi]){
            // cout<<h<<" ";
            if(niv[h] == 0){
                niv[h]= niv[vi]+1;  
                q.push(h);
            }
        }
    }
    // cout<<"\n";
    dp[lst]= aux;
    // for(auto a:dp)cout<<a<<" ";
    // cout<<"\n";
    q.push(lst);
    fill(niv.begin(),niv.end(),0);
    niv[lst]= 1;
    // cout<<"------\n";
    // for(auto a:S)cout<<a<<" ";
    // cout<<"\n";
    while(!q.empty()){
        auto vi = q.front();
        q.pop();
        for(auto h :grafo[vi]){
            if(niv[h] == 0){
                niv[h]= niv[vi]+1;
                dp[h] = dp[vi]-(2*S[h])+S[vi];
                S[h] = S[vi];
                q.push(h);
            }
        }
    }
    // for(auto a:dp)cout<<a<<" ";
    // cout<<"\n";
    ll mx = *max_element(dp.begin(),dp.end());
    cout<<mx<<"\n";
    return 0;
}