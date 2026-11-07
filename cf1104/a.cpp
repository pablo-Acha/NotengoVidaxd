#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--)
    {   
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll pre(n);
        ll mn = 1e9;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]<mn){
                mn = arr[i];
            }
            sum+=mn;
        }
        cout<<sum<<"\n";
        
    }
    return 0;
}