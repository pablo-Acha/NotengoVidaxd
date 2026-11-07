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
    ll n;cin>>n;
    vll arr(n);for(auto &a:arr)cin>>a;
    ll mx = 0;
    for (int i = 1; i < n; i++)
    {
        if(arr[i]<=arr[i-1]){
            ll aux = 0;
            while(i<n && arr[i]<=arr[i-1]){
                aux++;
                i++;
            }
            mx = max(mx,aux);
            i--;
        }
    }
    cout<<mx<<"\n";
    return 0;   
}