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
        for(auto &a:arr)cin>>a;
        vll imp(n);
        vll par(n);
        if(arr[n-1]&1)imp[n-1] = 1;
        else par[n-1] = 1;
        if(n == 1){
            res(imp,x);
            continue;
        }
        if(arr[n-2]&1)imp[n-2] = 1;
        else par[n-2] = 1;
        if(n == 2){
            res(imp,x);
            continue;
        }
        if(arr[n-3]&1){
            imp[n-3] = par[n-1]+1;
        }
        else{ 
            par[n-2] = imp[n-1]+1;
        }
        if(n == 3){
            res(imp,x);
            continue;
        }
        for (int i = n-4; i >=0; i--)
        {
            if(arr[i]&1){
                imp[i] = max(par[i+2],par[i+3])+1;
                par[i] = max(imp[i+2],imp[i+3])+1;
            }else{
                imp[i] = max(imp[i+2],imp[i+3])+1;
                par[i] = max(par[i+2],par[i+3])+1;
            }
        }
        res(imp,x);

    }
       
    return 0;
}