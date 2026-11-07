#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
    int n,m;cin>>n>>m;
    vll arr(m);
    for(auto &a:arr)cin>>a;
    sort(arr.begin(),arr.end());
    ll diff = 1e9;
    for (int i = n-1; i < m; i++)
    {
        diff = min(arr[i]-arr[i-n+1],diff);
    }
    cout<<diff<<"\n";
    
    return 0;
}