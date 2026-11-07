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
        sort(arr.begin(),arr.end());
        ll res = 0;
        ll mx = *max_element(arr.begin(),arr.end());
        for (int i = n-1; i >= 2; i--)
        {
            for (int j = i-1; j >= 1; j--)
            {
                ll mn = max(arr[i]-arr[j],mx-arr[i]-arr[j]);
                ll aux = upper_bound(arr.begin(),arr.begin()+j,mn)-arr.begin();
                res+= j-aux;
            }
        }
        cout<<res<<"\n";
    }
    
    return 0;
}