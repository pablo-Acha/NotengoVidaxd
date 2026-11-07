#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){

    int n,k;cin>>n>>k;
    vll arr(n);for(auto &a:arr)cin>>a;
    ll x = 0;
    for (int i = 0; i < k; i++)
    {
        x+= arr[i];
    }
    vll brr(n-k+1);
    brr[0] = x;
    for (int i = 1; i < n-k+1; i++)
    {
        brr[i] = brr[i-1]-arr[i-1]+arr[i-1+k]; 
    }
    
    
   
    
    ll res = min_element(brr.begin(),brr.end()) - brr.begin();
    cout<<res+1<<"\n";
    return 0;
}