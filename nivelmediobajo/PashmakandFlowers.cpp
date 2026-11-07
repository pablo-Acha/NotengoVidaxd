#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
// #include <iomanip>

int main(){
    ll n;cin>>n;
    vll arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    ll mn = *min_element(arr.begin(),arr.end());
    ll mx = *max_element(arr.begin(),arr.end());
    ll cntx = 0, cntmn = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == mn){
            cntmn++;
        }else if(arr[i] == mx){
            cntx++;
        }
    }
    if(mn == mx){
        ll res = ((cntmn-1)*(cntmn))/2;
        cout<<0<<" "<<res<<"\n";
    }else{
        cout<<(mx-mn)<<" "<<(cntmn*cntx)<<"\n";
    }
    return 0;
}