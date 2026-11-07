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
        map<ll,ll> L,R;
        for (int i = 0,j = n-1; i < n; i++,j--)
        {
            if(L.find(arr[i]) == L.end())L[arr[i]] = i;
            if(R.find(arr[j]) == R.end())R[arr[j]] = j;
        }
        ll mn = 1e9;
        for (int i = 0; i < n; i++)
        {
            ll mx = 0;
            ll aux = i - (L[arr[i]]-i);
            ll aux2 = n-1 - i -(R[arr[i]]-i);
            mx = max(aux,aux2);
            mn = min(mn,mx);
        }
        cout<<mn<<"\n";
    }
    return 0;
}