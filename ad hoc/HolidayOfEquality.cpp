#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
    int n;cin>>n;
    vll arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    ll mx = *max_element(arr.begin(),arr.end());
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        res+= (mx-arr[i]);
    }
    cout<<res<<"\n";
}
