#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll gaus(ll n){return n*(n+1) /2;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n),brr(n);
        for(auto &a:arr)cin>>a;
        for(auto &a:brr)cin>>a;
        ll res =0; 
        for (int i = 0; i < n; i++)
        {
            if(arr[i]>brr[i]){
                swap(arr[i],brr[i]);
            }
            res+= brr[i];
        }
        ll mx = *max_element(arr.begin(),arr.end());
        res+= mx;
        cout<<res<<"\n";
   }    

    return 0;
}