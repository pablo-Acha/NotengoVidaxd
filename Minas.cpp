#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

const ll MOD = 998244353;

bool f(ll mid,ll k ,vll arr){
    for (int i = (int)arr.size() - 1; i >= 0; i--)
    {
        if(arr[i]<mid){
            for (int j = i; j >= 0 && k>0; j--,k--)
            {
                arr[j]+=k;   
            }            
            break;
        }
    }
    for (int i = (int)arr.size() - 1; i >= 0; i--)
    {
        if(arr[i]<mid){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k;cin>>n>>k;
    vll arr(n);for(auto &a:arr)cin>>a;

    ll l = 1, r= 1e9+n+10, mid;
    while(l<=r){
        mid = (l+r)/2;
        if(f(mid,k,arr)){
            l  = mid+1;
        }else{
            r = mid-1;
        }
    }         
    cout<<r<<"\n";
    return 0;
}