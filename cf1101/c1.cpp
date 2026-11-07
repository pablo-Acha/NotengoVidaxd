#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,x,c;cin>>n>>x>>c;
        string s;cin>>s;
        vll pila;
        vll base;
        for (int i = 0; i < n; i++)
        {
             if(s[i] == 'A' || s[i] =='I'){
                 pila.push_back(1);   
                 base.push_back(s[i] == 'A');
             }else{
                if(pila.size()>=1)pila[pila.size()-1]++;
             }
        }
        vll backup = pila;
        sort(pila.begin(),pila.end(),greater<ll>());
        ll acc = 0;
        for(auto a:pila)cout<<a<<" ";
        cout<<"\n";
        for(auto a:backup)cout<<a<<" ";
        cout<<"\n";
        for (int i = 0; i < pila.size(); i++)
        {
            if(pila[i]>=max(backup[i],c)){
                ll aux = pila[i]-max(backup[i],c);
                acc+= aux;
                pila[i]-= aux;
            }else if(pila[i]<c){
                ll aux = min(acc,c-pila[i]);
                acc-=aux;
                pila[i]+=aux;
            }
        }
        acc = 0;
        for (int i = pila.size() - 1; i >= 0; i--)
        {
            if(i>= x&& base[i] == 1)acc+= pila[i];
            else{
                if(pila[i]<c){
                    ll aux = min(acc,c-pila[i]);
                    acc-=aux;
                    pila[i]+= aux;
                }
            }
        }
        
        ll res = 0;
        for (ll i = 0; i < min(x,ll(pila.size())); i++)
        {
            // cout<<i<<" ";
            res+= min(c,pila[i]);
        }
        cout<<res<<"\n";
    }
    return 0;
}