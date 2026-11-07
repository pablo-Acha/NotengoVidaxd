#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll gaus(ll n){
    return (n*(n+1))/2;
}

int main(){
    ll n;cin>>n;
    ll m = 0;
    vll arr(n);
    for(auto &a:arr){
        cin>>a;
        m+= ((a/abs(a))  == -1);
    }
    vll brr(m);
    vll crr(m);
    ll acc = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        if((arr[i]/abs(arr[i])) == -1){
            brr[j] = acc+1;
            acc = 0;
            j++;
        }else{
            acc++;
        }      
    }
    acc = 0;
    for (int i = n-1, j = m-1; i >=0; i--)
    {
        if((arr[i]/abs(arr[i])) == -1){
            crr[j] = acc+1;
            acc = 0;
            j--;
        }else{
            acc++;
        }      
    }
    // for(auto a:brr)cout<<a<<" ";
    // cout<<"\n";
    // for(auto a:crr)cout<<a<<" ";
    // cout<<"\n";
    ll x  = 0,y = 0;
    ll xx = 0, yy = 0;
    for (int i = m-1, j = 0; i>=0; i--,j++)
    {
        if(j&1){
            xx += crr[i];
            x+= brr[i] *xx;
        }else{
            yy += crr[i];
            y+= brr[i]*yy;
        }
    }
    cout<<y+x<<" ";
    x = 0,y = 0;
    xx = 0,yy = 0;
    for (int i = m-2, j = 0; i>=0; i--,j++)
    {
        if(j&1){
            xx += crr[i+1];
            x+= brr[i] *xx;
        }else{
            yy += crr[i+1];
            y+= brr[i]*yy;
        }
    }
    ll aux = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]/abs(arr[i]) == -1){
            aux += gaus(cnt);
            cnt= 0;
        }else{
            cnt++;
        }
    }
    

    cout<<y+x+aux+gaus(cnt)<<"\n";

    return 0;
}