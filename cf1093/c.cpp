#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll gaus(ll n){
    return (n*(n+1))/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll p,q;cin>>p>>q;
        bool f = 0;
        for (int i = 1; i < (2*1e4)+100 && !f; i++)
        {
            ll dos = q;
            ll uno = p;
            if(gaus(i)*2>q+(p/2)){
                break;
            }

            dos -= gaus(i)*2;
            if(dos<0){
                uno -= (abs(dos)*2);
                dos  = 0;
                if(uno%((i*2)+1) == 0){
                    cout<<i<<" "<<i+(uno/((i*2)+1))<<"\n";
                    f = 1;
                    break;
                }
            }else{
                ll aux = dos/i +((dos%i)>0);
                if(dos%i>0){
                    uno-=(i-(dos%i))*2; 
                }
                // cout<<uno<<"\n";
                uno-=aux;
                // cout<<uno<<"\n";
                if(uno<0)continue;
                if(uno%((i*2)+1) == 0){
                    cout<<i<<" "<<i+(uno/((i*2)+1))+(aux)<<"\n";
                    // cout<<"xxx"<<"\n";
                    f = 1;
                    break;
                }
            }


        }
        if(!f){
            cout<<-1<<"\n";
        }
    }
    return 0;   
}