#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()
ll poww(ll base, ll ex){
    ll res = 1;
    for (int i = 0; i < ex; i++)
    {
        res*= base;
    }
    return res;
}


bool backTracking(ll pos, ll a,ll b,vll &clave, ll fn){
    // cout<<pos<<" "<<a<<" "<<b<<"\n";
    // for(auto x:clave)cout<<x<<" ";
    // cout<<"\n------\n";
    if(pos == fn){ 
        return b == 0;
    }
    ll p = a%10;
    for (int i = 0; pow(p,i) <= b; i++)
    {
        ll aux =b-(poww(p,i)*poww(10,pos)); 
        if(aux%poww(10,pos+1) == 0){
            // cout<<aux<<" "<<i<<" "<<pos<<"\n";
            clave.push_back(i);
            if(!backTracking(pos+1, a/10,aux, clave, fn)){
                clave.pop_back();
            }else{
                return true;
            }
        }
    }
    return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a,b;cin>>a>>b;
    ll cnt = 0;
    ll aux = a;
    if(aux == 0)cnt = 1;
    while(aux){
        cnt++;
        aux/=10;
    }
    vll clave;
    // cout<<cnt<<"\n";
    if(backTracking(0, a,b,clave,cnt)){
        reverse(all(clave));
        for (int i = 0; i < clave.size(); i++)
        {
            cout<<clave[i]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}