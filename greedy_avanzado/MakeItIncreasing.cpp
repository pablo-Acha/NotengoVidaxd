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
        vll arr(n);for(auto &a:arr)cin>>a;
        bool f = 1;
        ll cnt = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            while(arr[i]>= arr[i+1]  && arr[i]){
                cnt++;
                arr[i]/=2;
            }
            if(arr[i] == arr[i+1]){
                f = 0;
                break;
            }
        }
        if(f){
            cout<<cnt<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }   
       
    return 0;
}