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
    while(t--){
        ll n;cin>>n;
        vll arr(4*n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = i+1;
        }
        for (int i = n,j = 1; i < 2*n; i++,j++)
        {
            arr[i] = j;
        }
        arr[2*n] = n;
        for (int i = (2*n )+1,j = 1; i < 3*n; i++,j++)
        {
            arr[i] = j;
        }
        for (int i = 3*n,j = 1; i < 4*n; i++,j++)
        {
            arr[i] = j;
        }
        for(auto a:arr)cout<<a<<" ";
        cout<<"\n";
    }
    return 0;
}