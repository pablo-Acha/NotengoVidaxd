#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n),brr(n);
        for(auto &a:arr)cin>>a;
        for(auto &a:brr)cin>>a;
        vll si(n);
        ll val = 2;
        for (int i = 19; i >= 0; i--)
        {
            ll a = 0,b = 0;
            for (int j = 0; j < n; j++)
            {
                a+= (arr[j]>>i)&1;
                b+= (brr[j]>>i)&1;
            }
            // cout<<i<<" "<<a<<" "<<b<<"\n";

            for (int j = 0; j < n; j++)
            {
                if(si[j])continue;
                ll p =(arr[j]>>i)&1 ,s = (brr[j]>>i)&1;
                if(p==s)continue;;
                if((b&1) == (a&1))continue;
                else si[j] = 1;
                if(j&1){
                    if(b%2 == 0 && (a&1)){
                        // si[j] = 1;
                        a -= (arr[j]>>i)&1;
                        b -= (brr[j]>>i)&1;
                        swap(arr[j],brr[j]);
                        a += (arr[j]>>i)&1;
                        b += (brr[j]>>i)&1;
                    }
                }else{                    
                    if(a%2 == 0 && (b&1)){
                        // si[j] = 1;
                        a -= (arr[j]>>i)&1;
                        b -= (brr[j]>>i)&1;
                        swap(arr[j],brr[j]);
                        a += (arr[j]>>i)&1;
                        b += (brr[j]>>i)&1;
                    }
                }
            }
            // cout<<i<<" "<<a<<" "<<b<<"\n";
        }
        ll h = arr[0],j =brr[0];
        for (int i = 1; i < n; i++)
        {
            h = h^arr[i];
            j = j^brr[i];
        }
        if(h>j){
            cout<<"Ajisai"<<"\n";

        }else if(j>h){

            cout<<"Mai"<<"\n";
        }else{

            cout<<"Tie"<<"\n";
        }
        if(val ==0){
        }else if(val == 1){
        }else{
        }
        
        
        
    }
    return 0;
}