#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<ll> vll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n,k;cin>>n>>k;
        vll arr(n),brr(n);
        for(auto &a:arr)cin>>a;
        for(auto &a:brr)cin>>a;
        ll p = 0;
        bool f= 1;
        bool f2 =1; 
        for (int i = 0; i < n; i++)
        {
            if(arr[i]<brr[i]){
                f = 0;
                break;
            }else{
                p+= arr[i]-brr[i];
            }
        }
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        ll p2 = k;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]<brr[i]){
                f2  = 0;
                break;
            }else{
                p2+=arr[i]-brr[i];
            }
        }
        if(f && f2){
            cout<<min(p,p2)<<"\n";
        }else if(f){
            cout<<p<<"\n";
        }else if(f2){
            cout<<p2<<"\n";
        }else{
            cout<<-1<<"\n";
        }
        
    }
}