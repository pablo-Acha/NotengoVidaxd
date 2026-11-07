#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll gaus(ll n){return n*(n+1) /2;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    ll n;cin>>n;
    vll arr(n);for(auto &a:arr)cin>>a;
    vll brr(n);for(auto &a:brr)cin>>a;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]<brr[i]){
            swap(arr[i],brr[i]);
        }
    }
    ll a = arr[0],b = brr[0];
    vll res;
    for (int i = 1; i < n; i++)
    {
        if(a<=brr[i] || b >){
            res.push_back(a)
        }else{

        }
    }
    
    return 0;
}