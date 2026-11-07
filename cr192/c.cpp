#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        vll arr;
        
        map<ll,ll> mp;
        for (int i = 0; i < n; i++)
        {
            ll a;cin>>a;
            mp[a]++;
        }
        for(auto [a,v]:mp){
            arr.push_back(v);
        }
        sort(arr.begin(),arr.end(),greater<ll>());
        arr.push_back(0);
        vll brr;
        ll mx = arr[0];
        for (int i = 0; i < arr.size(); i++)
        {
            // cout<<arr[i]<<" ";
            if(arr[i]<mx){
                mx = arr[i];
                ll aux = arr[i-1]-arr[i];
                for (int j = 0; j < aux; j++)
                {
                    brr.push_back(i);
                }  
            }
        }
        // cout<<"\n";
        sort(brr.begin(),brr.end(),greater<ll>());
        // for(auto a:brr)cout<<a<<" ";
        // cout<<"\n";
        ll m = n;
        ll res = 0;
        set<ll> vis;
        for (int i = 0; i < brr.size(); i++)
        {
            if(k>=m && vis.find(brr[i]) == vis.end()){
                vis.insert(brr[i]);
                ll aux = k-m;
                res += (aux%brr[i] == 0);
            }
            m-=brr[i];
        }
        cout<<res<<"\n";
        
    }

    return 0;
}