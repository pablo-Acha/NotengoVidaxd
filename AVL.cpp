#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
const ll MOD  = 1e9 + 7; 
const ll MOD1  = 1e9 + 6; 

long long restaModular(long long a, long long b) {
    return ((a - b) % MOD + MOD) % MOD;
}
long long potenciaBinaria(long long base, long long potencia) {
    long long resultado = 1;
    while (potencia > 0) {
        if (potencia & 1)
            resultado = (resultado*base)%MOD;
        base = (base*base)%MOD;
        potencia >>= 1;
    }
    return resultado;
}
int main(){
    vll arr(1003);
    vll brr(1003);
    vll potencias(1003);
    vll potenciasF(1003);
    arr[1] = 2;
    brr[1] = 1;
    potencias[1] = 1;
    potenciasF[1] = 1;
    for (int i = 2; i < 1003; i++)
    {
        arr[i] = (((arr[i-1]*arr[i-1])%MOD)+1)%MOD;
    }
    for (int i = 2; i < 1003; i++)
    {
        brr[i] += restaModular(((((2*arr[i-1])%MOD)*brr[i-1])%MOD)   ,  ((brr[i-1]*brr[i-1])%MOD));
    }
    for (int i = 0; i <= 4; i++)
    {
        cout<<brr[i]<<" ";
    }
    for (int i = 2; i < 1003; i++)
    {
        potencias[i] = (potencias[i-1]*potencias[i-1])%MOD;
    }
        for (int i = 2; i < 1003; i++)
    {
        potenciasF[i] = (potenciasF[i-1]*potenciasF[i-1])%MOD1;
    }
    ll t;cin>>t;
    while(t--){
        ll m,h;cin>>m>>h;
        ll nodos = h+1;
        ll arbol = min(m+1,nodos);
        ll val = nodos-arbol+1;
        cout<<val<<"----";
        ll resto= potenciasF[val]-1 == 0? 0:potenciaBinaria(brr[arbol],potenciasF[val]-1); 
        cout<<resto<<"*****";      
        ll suma = (((potencias[val]*potenciaBinaria(arr[arbol],val-1))%MOD)*brr[arbol])%MOD;
        cout<<suma<<"-----";
        ll res = restaModular(suma,resto);
        cout<<res<<"\n";
    }
    return 0;
}