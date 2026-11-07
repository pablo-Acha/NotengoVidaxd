#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
ll val[1000001];

int main(){
    ll n;cin>>n;
    map<ll,ll> mp;
    vll arr(n);for(auto &a:arr){cin>>a;mp[a]++;}
    sort(arr.begin(),arr.end());
    for (auto [x,y]:mp)
    {
        for (int j = x; j <= 1e6; j+=x)
        {
            val[j] += y;
        }
    }
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        if(val[arr[i]] == 1){
            res++;
        }
    }
    cout<<res<<"\n";

    return 0;
}