#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll gaus(ll n){
    return (n*(n+1))/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll res = 0;
        for (int i = 1; i < n; i++)
        {
            if(arr[i] == arr[i-1]){
                ll aux = 1;
                while(i<n && arr[i] == arr[i-1]){
                    i++;
                    aux++;
                }
                i--;
                res = max(aux,res);
            }
        }
        if(res<m){
            cout<<"YES\n";
        }   else{
            cout<<"NO\n";
        }     

    }   
    return 0;   
}