#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
const ll MOD =998244353;

bool verificar(vll &v, ll top){
    
    
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i]<top){
            return false;
        }
    }
    return true;
}

ll permutacion(ll n){
    ll res = 1;
    for (int i = 1; i <= n; i++)
    {
        res= (res *i)%MOD;
    }
    return res;
}

ll combinatoria(ll n, ll x){
    ll res = 1;
    for (int i = n-x + 1; i <= n; i++)
    {
        res = (res*i)%MOD;
    }
    return res;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vll arr(n+1);
        for(auto &a:arr)cin>>a;
        if(n == 1){
            cout<<1<<endl;
            continue;
        }
        vll brr(n);
        for (int i = 0; i < n; i++)
        {
            brr[i] = arr[i+1];
        }
        ll val = arr[0];
        sort(brr.begin(),brr.end(),greater<ll>());
        ll mx = brr[0];
        for (int i = 0; i < n; i++)
        {
            if(brr[i]<mx-1){
                ll r = min((mx-1)-brr[i],val);
                val -=r;
                brr[i]+=r;
            }
        }
        // cout<<val<<endl;
        // cout<<mx-1<<endl;
        if(!verificar(brr,mx-1)){
            cout<<0<<endl;
            continue;
        }
        // cout<<"a"<<endl;
        ll maximos = 0;
        for (int i = 0; i < n; i++)
        {
            maximos+= brr[i] == mx;
        }
        if(maximos==n){
            ll aux = val/n;
            val = val -( val/n * n);
            for (int i = 0; i < n; i++)
        {
            brr[i]+=aux;
        }   
        }
        if(brr[0] == 0){
            cout<<0<<endl;
            continue;
        }   
        // cout<<val<<endl;
        // cout<<maximos<<endl;
        if(val >= n-maximos){
            ll altos = (val-(n-maximos))%n == 0?n:(val-(n-maximos))%n;
            ll bajos = n-altos;
            ll pAltos = permutacion(altos);
            ll pbajos = permutacion(bajos);
            ll comb = combinatoria(n,bajos);
            // cout<<altos<<" "<<bajos<<" "<<pAltos<<" "<<pbajos<<endl;
            ll res = (((pAltos*pbajos)%MOD )*comb)%MOD;
            cout<<res<<endl;
        }else{
            ll altos = val+maximos;
            ll bajos = n-altos;
            ll pAltos = permutacion(altos);
            ll pbajos = permutacion(bajos);
            ll comb = combinatoria(n-maximos,val);
            ll res = (((pAltos*pbajos)%MOD )*comb)%MOD;
            cout<<res<<endl;
        }
    }
}