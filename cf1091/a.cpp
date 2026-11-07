#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        ll res = 0;
        for (ll i = 0,a; i < n; i++)
        {
            cin>>a;
            res+=a;
        }
        if((res&1) || ((n*k)%2 ==0)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }



    return 0;
}