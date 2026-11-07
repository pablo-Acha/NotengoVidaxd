#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ll a,b;cin>>a>>b;
    ll curr = max(a,b), charge = min(a,b);
    ll res = 0;
    while(curr>2){
        curr-=2;
        res++;
        charge++;
        if(curr<=2){
            swap(curr,charge);
        }
    }    
    cout<<res+((curr == 2) ||(charge  == 2))<<"\n";   
    return 0;
}