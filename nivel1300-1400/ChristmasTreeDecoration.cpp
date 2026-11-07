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
        ll n;cin>>n;
        ll sob;cin>>sob;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll mx = *max_element(arr.begin(),arr.end());
        ll f = 0;
        for (int i = 0; i < n; i++)
        {
            f+= arr[i] == mx;
        }
        
        bool flag= 1;
        for (int i = 0; i < n; i++)
        {
            if(arr[i] <mx-1){
                ll aux = min(mx-1-arr[i],sob);
                arr[i]+=aux;
                sob-=aux;
            }
            if(arr[i]<mx-1){
                flag = 0;
                break;
            }
        }
        if(!flag){
            cout<<0<<"\n";
            continue;
        }else{
            if(sob>n-f){
                ll res = 1;
                sob -= n-f;
                sob = sob%n == 0?n:sob%n;
                for (int i = sob; i >0; i--)
                {
                    res = (res*i)%MOD;
                }
                ll e = C(n,sob);
                ll p = 1;
                for (int i = 1; i <= n-sob; i++)
                {
                    p = (p*i)%MOD;
                }
                
                res = (res *e)%MOD;
                res = (res*p)%MOD;
                cout<<res<<"\n";
            } else{
                ll m = n-f;
                ll aux = 1;
                for (int i = 1; i <= f+sob; i++)
                {
                    aux = (aux*i)%MOD;
                }
                
                ll p = n-f-sob;
                ll pfac = 1;
                for (int i = 1; i <= p; i++)
                {
                    pfac  = (pfac*i)%MOD;
                }
                
                ll e = C(m,sob);
                // cout<<e<<"\n";
                // cout<<pfac<<"\n";
                ll res = ((aux * e) % MOD);
                res = (res* pfac)%MOD;
                cout<<res<<"\n";
            }
        }
    }    
    
    return 0;
}