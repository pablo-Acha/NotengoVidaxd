#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--) {
        ll n,k;cin>>n>>k;
        ll p =0;
        ll aux = n;
        while(aux){
            p++;
            aux/=2;
        }
        ll res = 0;
        if(k<p){
            res = (1LL<<k);
            // cout<<"x"<<" ";
        }else{
            aux = 1;

            for (int i = 0; i < 35; i++)
            {
                if((n>>i) &1){
                    res+= (1LL<<i);
                }
            }
            res++;
            
        }
        cout<<res<<"\n";
    }
}