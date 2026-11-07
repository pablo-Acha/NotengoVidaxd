#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ll n,m;cin>>n>>m;
    vector<pair<ll,ll>> arr(n);
    ll acc = 0;
    for (int i = 0; i < n; i++)
    {
        auto &[b,a] = arr[i];
        cin>>a>>b;
        acc+=a;
        b = a-b;
    }
    sort(arr.begin(),arr.end(),greater<pair<ll,ll>>());
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(acc<=m)break;
        acc-=arr[i].first;
        cnt++;
    }
    if(acc<=m){
        cout<<cnt<<"\n";
    }else{
        cout<<-1<<"\n";
    }
    return 0;
}