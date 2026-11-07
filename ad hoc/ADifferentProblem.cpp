#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ll a,b;
    while(cin>>a){
        cin>>b;
        ll res = max(a,b) - min(a,b);
        cout<<res<<"\n";
    }
    return 0;
}