#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;


int main(){
    int t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        vll arr(n);
        for (int i = 0; i < n; i++) 
        {
            cin>>arr[i];
        }
        ll x;cin>>x;
        ll v = arr[x-1];
        ll j = x;
        ll curr = v;
        ll valI = 0;
        while(j<n){
            if(curr!=arr[j]){
                curr = arr[j];
                valI++;
            }
            j++;
        }
        valI+= (curr!=v);
        curr = v;
        ll valD = 0;
        j = x-2;
        while(j>=0){
            if(curr!=arr[j]){
                curr = arr[j];
                valD++;
            }
            j--;
        }
        valD+= (curr!=v);
        ll res  = max(valD,valI);
        cout<<res<<"\n";
    }



    return 0;
}