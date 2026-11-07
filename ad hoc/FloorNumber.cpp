#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll im= 0;
        vll arr(n);for(auto &a:arr){cin>>a;
        if(a&1)im++;}
        ll sum = accumulate(arr.begin(),arr.end(),0);
        if(sum&1 || (((sum/2)&1) && im == 0)){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
    return 0;
}