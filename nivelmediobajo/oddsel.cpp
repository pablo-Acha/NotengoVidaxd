#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
void res(vll &arr, ll x){
    ll r = *max_element(arr.begin(),arr.end());
    if(r>=x){
        cout<<"Yes\n";
    }else{

        cout<<"No\n";
    }
}
int main(){
    ll t;cin>>t;
    while(t--){
        ll x,n;cin>>n>>x;
        vll arr(n);
        ll imp = 0,par = 0;
        for(auto &a:arr){
            cin>>a;
            if(a&1)imp++;
            else par++;
        }
        if(x == n){
            if(imp&1){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }else{
            if((imp>0 && par>0) || (imp>0 && (x&1))){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }

    }
       
    return 0;
}