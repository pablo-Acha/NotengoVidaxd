#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n) { return n * (n + 1) / 2; }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m,x,y;cin>>n>>m>>x>>y;
    ll z = x-y;
    vll arr(n);
    vll cant(n);
    vll brr(m);
    for(auto &a:arr)cin>>a;
    for(auto &a:brr)cin>>a;
    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());
    ll j = 0;
    for (int i = 0; i < n; i++)
    {
        while(j<m && cant[i]<x && brr[j]<=arr[i])
        {
            cant[i]++;j++;
        }
    }
    if(j<m){
        cout<<"impossible"<<"\n";
        return 0;
    }
    ll res = 0;
    ll acc = 0;
    ll vacio = 0;
    //     for(auto a:cant)cout<<a<<" ";
    // cout<<"\n";

    for (int i = 0; i < n; i++)
    {
        if(cant[i]<y){
            vacio += y-cant[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(cant[i]>y){
            ll aux =min(cant[i]-y,vacio);
            acc+= aux;
            vacio -=aux;
            cant[i]-=aux;
        }else if(cant[i]<y){
            ll aux = min(acc,y-cant[i]);
            acc -= aux;
            cant[i]+=aux;
            if(y>cant[i])vacio -= y-cant[i];
        }
    }
    // for(auto a:cant)cout<<a<<" ";
    // cout<<"\n";
    sort(cant.begin(),cant.end());
    // for(auto a:cant)cout<<a<<" ";
    // cout<<"\n";
    vacio = x-cant[n-1];
    for (int i = 0; i < n; i++)
    {
        if(cant[i]<=y)res++;
        else break;
    }
    
    for (int i = n - 2; i >= 0; i--)
    {
        if(cant[i]<=y)break;
        if(cant[i]-y<=vacio){
            res++;
            vacio -= cant[i]-y;
        }else{
            cant[i]-=vacio;
            vacio = x-cant[i];
        }   
    }
    
    
    
    cout<<res<<"\n";
    return 0;
}