#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ll n;cin>>n;
    map<ll,string> mp;
    mp[1] = "Sheldon";
    mp[2] = "Leonard";
    mp[3] = "Penny";
    mp[4] = "Rajesh";
    mp[5] = "Howard";

    ll h = 5;
    while(h<n){
        n-=h;
        h*=2;
    }
    ll pr = h/5;
    ll res = 1;
    while (n>pr)
    {
        res++;
        n-=pr;
    }
    cout<<mp[res]<<"\n";
    
    return 0;
}