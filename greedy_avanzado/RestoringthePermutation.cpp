#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}
int main(){
        ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        string s;cin>>s;
        map<char,vll> mp;
        map<char,ll> mps;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]].push_back(i);
        }
        for(auto [a,r]:mp){
            for(auto c:r){
                cout<<c<<" ";
            }
            cout<<"\n";
        }
        ll mx = -1;
        for (auto it = prev(mp.end()); ; it =prev(it))
        {
            auto [a,val] = *it;
            auto p = upper_bound(val.begin(),val.end(),mx);
            if(p == val.end()){
                mps[a] = *(p-1);
                mx = max(*(p-1),mx);
            }else{
                mps[a] = *p;
                mx = max(*(p),mx);
            }
            if(it ==mp.begin())break;
        }
        string x(s.size(),'.');
        for(auto [a,val]:mps){
            x[val] = a;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if(x[i]!='.')cout<<x[i];
        }
        cout<<"\n";
    }
       
    return 0;
}