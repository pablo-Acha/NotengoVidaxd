#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll gaus(ll n){return n*(n+1) /2;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        ll unos = 0,res = 0;
        bool f = 0;
        vll arr(n);
        ll dif = 0;
        for(auto &a:arr){cin>>a;unos+=(a == 1);dif = (a !=1)?a:0;}
        
        if(unos == n-1) {
            res = dif+ min(dif/2,unos);
        }else{
            for (int i = 0; i < n; i++)
            {
                if(arr[i] !=1){
                    ll aux = min((arr[i]/2)-1,unos);
                    res+= arr[i]+aux;
                    unos -= aux;
                }
            }
        } 
        if(res<3){
            cout<<0<<"\n";
        }else{
            cout<<res<<"\n";
        }
        
    }
    

    return 0;
}