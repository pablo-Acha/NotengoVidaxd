#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll c1 = (n/3) +(n%3 == 1) ,c2 = (n/3)+(n%3 == 2);
        cout<<c1<<" "<<c2<<"\n";
    }

    
    return 0;
}