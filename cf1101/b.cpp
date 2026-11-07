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
        vll res(n);
        res[0] =arr[0];
        ll mn = arr[0];
        ll sum = arr[0];
        for (int i = 1; i < n; i++)
        {
            sum+=arr[i];
            ll aux = sum/(i+1);
            if(aux> mn){
                res[i] = mn;
            }else{
                res[i] = aux;

            }
            mn = min(res[i],mn);
        }
        for(auto a:res)
        {
            cout<<a<<" ";
        }
        cout<<"\n";
    }
    return 0;
}