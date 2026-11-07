#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;
vll primos;
vll aux(1e6+10,1);
void init(){
    aux[0] = 0;
    aux[0] = 0;
    for (int i = 2; i < 1e6+10; i++)
    {
        if(aux[i] == 0)continue;
        primos.push_back(i);
        for (int j = i*2; j < 1e6+10; j+=i)
        {
            aux[j] = 0;
        }
    }
    
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    ll a,b;cin>>a>>b;
    ll g = gcd(a,b);
    ll res = 0;
    for(ll i = 2; i*i <= g; i++){
        if(g % i == 0){
            res++;
            while(g % i == 0) g /= i;
        }
    }

    if(g > 1) res++;
    cout<<res+1<<"\n";
    return 0;
}