#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--) {
        ll n;cin>>n;
        ll cnt = 0;
        while(n){
            cnt++;
            n/=10;
        }
        cout<<1;
        for (int i = 0; i < cnt-1; i++)
        {
            cout<<"0";
        }
        cout<<"1\n";
        
    }
}