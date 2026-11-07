#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ll n;cin>>n;
    if(n == 1){
        cout<<1<<"\n";
        return 0;
    }
    ll pow = 1;
    int i = 0;
    while (pow<((n/2)+(n&1)))
    {
        pow = pow<<1;
        i++;
    }
    cout<<i+2<<"\n";
    return 0;
}