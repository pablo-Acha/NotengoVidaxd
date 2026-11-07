#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;cin>>n>>m;
    vector<pair<ll,ll>> arr(n);
    for (int i = 0; i < n; i++)
    {
        auto &[a,b] = arr[i];
        cin>>a>>b;
    }
    sort(arr.begin(),arr.end());
    ll res = 0;
    for (int i = 0; i < n && m>0; i++)
    {
        auto [a,b] = arr[i];
        if(b<=m){
            m-=b;
            res+= (a*b);
        }else{
            res+=m*a;
            m= 0;
        }
    }
    cout<<res<<"\n";
    return 0;
}