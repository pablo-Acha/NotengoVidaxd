#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;


int main(){
    ll n;cin>>n;
    vll arr(n+1);
    for (int i = 1; i < n+1; i++)
    {
        cin>>arr[i];
    }
    ll m;cin>>m;
    vll brr = arr;
    sort(brr.begin(),brr.end());
    for (int i = 1; i <= n; i++)
    {
        arr[i] +=arr[i-1];
        brr[i] +=brr[i-1];
    }
    
    for (int i = 0; i < m; i++)
    {
        ll x,a,b;cin>>x>>a>>b;
        if(x == 1){
            cout<<arr[b]-arr[a-1]<<"\n";
        }else{
            cout<<brr[b]-brr[a-1]<<"\n";
        }
    }
       
    return 0;
}