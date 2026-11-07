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
    long double n,k;cin>>n>>k;
    vector<long double> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        arr[i] = gaus(arr[i])/arr[i];
    }
    long double aux = 0;
    for (int i = 0; i < k; i++)
    {
        aux+= arr[i];
    }
    long double mx = aux;
    for (int i = 0; i+k < n; i++)
    {
        aux = aux -arr[i]+arr[i+k];
        mx = max(aux,mx);
    }
    cout << fixed << setprecision(9) << mx << "\n";
    return 0;
}