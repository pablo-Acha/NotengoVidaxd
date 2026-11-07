#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        vll freq(n+1);
        set<ll> vals;
        for (ll i = 0,a; i < n; i++)
        {
            cin>>a;
            freq[a]++;
            vals.insert(a);
        }
        ll a = vals.size();
        ll b = *max_element(freq.begin(),freq.end());
        if(a ==b ){
            cout<<a-1<<"\n";
        }else {
            ll res = min(a,b);
            cout<<res<<"\n";
        }
    }
    
    return 0;
}