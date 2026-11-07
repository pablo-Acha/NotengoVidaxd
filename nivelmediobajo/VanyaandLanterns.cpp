#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
// #include <iomanip>

int main(){
    long double n,k;cin>>n>>k;
    vector<long double> arr(n);
    for(auto &a:arr)cin>>a;
    sort(arr.begin(),arr.end());
    long double mx = max(arr[0],k-arr[n-1]);
    for (int i = 1; i < n; i++)
    {
        long double aux = (arr[i]-arr[i-1])/2;
        mx= max(mx,aux);
    }
    cout << fixed << setprecision(9) << mx << "\n";
    
    return 0;
}