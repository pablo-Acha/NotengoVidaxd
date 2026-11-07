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
    vll arr(n+1);;
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    bool f = 1;
    for (int i =1; i <= n; i++)
    {
        if(arr[i-1]<arr[i]){
            arr[i]--;
        }else if(arr[i-1]>arr[i]){
            f = 0;
            break;
        }
    }
    cout<<(f?"Yes\n":"No\n");
    
    return 0;   
}