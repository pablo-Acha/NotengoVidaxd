#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll gaus(ll n){return n*(n+1) /2;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        vll arr(n); for(auto &a:arr)cin>>a;
        ll f = 1;
        vll res;
        for (int i = n - 1; i >= 0; i--)
        {
            if(arr[i]*f >0){
                f *=-1;
                res.push_back(i+1);
            }
        }
        cout<<res.size()<<"\n";
        for(auto &a:res)cout<<a<<" ";
        cout<<"\n";
    }
         

    return 0;
}