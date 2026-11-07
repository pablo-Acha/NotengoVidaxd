#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll gaus(ll n){
    return (n*(n+1))/2;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;cin>>n>>m;
    vll arr(n),brr(m);
    for(auto &a:arr)cin>>a;
    for(auto &a:brr)cin>>a;
    sort(arr.begin(),arr.end());
    vector<vll> pos(n);
    vll res(m,-1);
    for (int i = 0; i < m; i++)
    {
        ll p = upper_bound(arr.begin(),arr.end(),brr[i])-arr.begin();
        p--;
        // cout<<"de"<<p<<"\n";
        if(p < 0)continue;
        pos[p].push_back(i);
    }
    vll cant;
    for (int i = 0; i < n; i++)
    {
        cant.push_back(arr[i]);
        if(pos[i].size()>0){
            // for(auto x:pos[i])cout<<x<<" ";
            // cout<<"\n";
            ll h = 0;            
            while(!cant.empty() && h<pos[i].size()){
                res[pos[i][h]]=cant[cant.size()-1];
                cant.pop_back(); 
                h++;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout<<res[i]<<"\n";
    }
    
    return 0;
}