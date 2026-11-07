#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
vll primos(1e6+7,1);


bool isprime(ll n){
    return primos[n]>0;
}
void init(){
    for (int i = 2; i < 1e6+7; i++)
    {
        if(primos[i] == 0)continue;
        for (int j = i*2; j < 1e6+7; j+=i)
        {
            primos[j] =0; 
        }
    }
}
int main(){
    ll n;cin>>n;
    vll arr(n);
    primos[0] = 0;
    primos[1] = 0;
    init();
    // for (int i = 0; i < 15; i++)
    // {
    //     cout<<primos[i]<<" ";
    // }
    // cout<<"\n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        ll aux = sqrt(arr[i]);
        // cout<<aux<<"\n";
        if(aux*aux == arr[i] && arr[i]>1 && isprime(aux)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    
    
    return 0;
}