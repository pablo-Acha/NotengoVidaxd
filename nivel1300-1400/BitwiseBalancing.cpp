#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll b,c,d;cin>>b>>c>>d;

        ll a = 0;
        bool f= 1;
        ll res = 0;
        for (int i = 0; i <= 61; i++)
        {
            ll left = (b>>i)&1, der = (c>>i)&1, r = (d>>i)&1;
            if(left == 1 && der == 0 ){
                if(r == 0){
                    f = 0;
                    break;
                }
            }else if(left == 1 && der == 1 ){
                if(r == 0){
                    a+= 1LL<<i;
                }
            }else if(left == 0 && der == 0){
                if(r == 1){
                    a+= 1LL<<i;
                }
            }else{
                if(r == 1){
                    f = 0;
                    break;
                }
            }  
        }
        if(f){
            cout<<a<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }
    
    return 0;
}