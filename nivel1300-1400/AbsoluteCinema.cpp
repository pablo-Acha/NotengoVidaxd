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
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll r(n);
        for (int i = 0; i < n-1; i++)
        {
            r[i] = (arr[i]-arr[i+1]);
        }
        ll aux = 0,aux1 = 0;
        // for(auto a:r){
        //     cout<<a<<" ";
        // }
        // cout<<"\n";
        vll res(n);
        for (int i = 0; i < n-2; i++)
        {
            res[i+1]= (r[i]-r[i+1])/2;
        }
        
        for (int i = 1,j = n-2; i < n-1; i++,j--)
        {
            aux+= i*res[i];
            aux1+= i*res[n-i-1];
        }
        // cout<<aux1<<"\n";
        res[n-1] = (arr[0]-aux)/(n-1);
        res[0] = (arr[n-1]-aux1)/(n-1);
        for(auto a:res)cout<<a<<" ";
        cout<<"\n";
        
    }
    return 0;
}