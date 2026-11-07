#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll gaus(ll n){
    return (n*(n+1))/2;
}
int main(){
    ll n,k;cin>>n>>k;
    vll arr(n+1),pa(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    vll val1(n+1),val2(n+1);
    vll vis(n+1),vis2(n+1);
    ll ci = 0,v = 0;
    queue<ll> qu;
    qu.push(1);
    vis[1] = 1;
    ll mx = 0;
    while(!qu.empty()){
        auto x = qu.front();
        qu.pop();
        val1[x] = v;
        mx=v;
        v++;
        if(vis[arr[x]]){
            ci = arr[x];
            continue;
        }
        vis[arr[x]] = 1;
        qu.push(arr[x]);
    }        
    if(k<=mx){
        for (int i = 1; i <= n; i++)
        {
            if(k == val1[i]){
                cout<<i<<"\n";
                break;
            }
        }        
    }else{
        k-=mx;
        v = 1;
        qu.push(ci);
        vis2[ci] = 1;
        while(!qu.empty()){
            auto x = qu.front();
            qu.pop();
            val2[x] = v;            
            if(vis2[arr[x]])continue;
            v++;
            vis2[arr[x]] = 1;
            qu.push(arr[x]);
        } 
        ll sear = k%v;
        if(sear == 0)sear = v;
        for (int i = 1; i <= n; i++)
        {
            if(val2[i] == sear){
                cout<<i<<"\n";
                break;
            }
        }
        
    }

    return 0;
}