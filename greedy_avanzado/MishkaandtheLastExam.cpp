#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll gaus(ll n){return n*(n+1) /2;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;cin>>n;
    vll arr(n);
    for (int i = 0; i < n/2; i++){
        cin>>arr[i];
    }
    ll mx = 0;
    for (int i = 1; i < n/2; i++)
    {
        ll aux = arr[i]-arr[i-1];
        if(aux >=mx){
            arr[i] = arr[i-1];
            arr[n-i-1] = aux;
        }else{
            ll aux2 = mx-aux;
            aux+= aux2;
                arr[i] = arr[i-1]-aux2;
                arr[n-i-1] = aux;
            }
            mx = max(mx,aux);
        //     if(arr[i]>arr[i-1]){
        // }
    }
    reverse(arr.begin(),arr.end());
    for(auto a:arr)cout<<a<<" ";
    cout<<"\n";

    return 0;
}