#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        vll arr(m);
        for(auto &a:arr)cin>>a;
        sort(arr.begin(),arr.end());
        vll brr;
        for (int i = 1; i < m; i++)
        {
            brr.push_back(arr[i]-arr[i-1]-1);
        }
        brr.push_back(arr[0]+n-arr[m-1]-1);
        sort(brr.begin(),brr.end(),greater<ll>());
        // for(auto a:brr)
        // cout<<a<<" ";
        // cout<<"\n";
        ll l = brr.size();
        ll inf = 0;
        vll res(l);
        for (int i = 0; i < l; i++)
        {
            ll aux = brr[i]/2 + (brr[i]&1);
            if(inf>=aux){
                res[i] += brr[i];
                continue;
            }
            res[i] += inf;
            inf++;
            if(inf>=aux){
                if(brr[i]&1)res[i] += inf-1;
                else res[i] += inf;
                continue;
            }
            res[i] += inf;
            inf++;
        }
        // for(auto a:res)
        // cout<<a<<" ";
        // cout<<"\n";
        ll r = 0;

        for(auto a:res)r+=a;
        // cout<<r<<"\n";
        r+= m;
        cout<<r<<"\n";
    }
    return 0;
}