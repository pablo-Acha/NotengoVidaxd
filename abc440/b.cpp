#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ll n;cin>>n;
    vll arr(n);
    map<ll,ll> mp;
    for(auto &a:arr)cin>>a;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]] = i;
    }
    
    sort(arr.begin(),arr.end());
    for (int i = 0; i < 3; i++)
    {
        cout<<mp[arr[i]]+1<<" ";
    }
    cout<<endl;
    return 0;
}