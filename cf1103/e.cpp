#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--)
    {   
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        map<ll,ll> mp;
        vector<pair<ll,ll>> vpp;
        for (int i = 0; i < n; i++)
        {
            if(mp.find(arr[i]) == mp.end()){
                mp[arr[i]] = i;
                auto ult = prev(mp.end());
                auto in = mp.begin();
                if(mp.size() == ult->first - in->first+1){
                    vpp.emplace_back(in->first,ult->first);
                }
                
            }else{
                
                ll aux = mp[arr[i]];
                for (auto it = mp.begin(); it != mp.end(); ) {
                    if (it->second <= aux)
                        it = mp.erase(it);
                    else
                        ++it;
                }
                mp[arr[i]] = i;
                auto ult = prev(mp.end());
                auto in = mp.begin();
                if(mp.size() == ult->first - in->first+1){
                    vpp.emplace_back(in->first,ult->first);
                }
                
                // cout<<"\n";
            }
        }
        for(auto [k,v]:vpp){
            cout<<k<<" "<<v<<"\n";
        }
        ll mx = 0;
        sort(vpp.begin(),vpp.end());
        for (int i = 0; i < vpp.size(); i++)
        {
            mx = max(mx,(vpp[i].second-vpp[i].first+1)/2);
            for (int j = i+1; j < vpp.size(); j++)
            {
                if(vpp[i].second+1 == vpp[j].first){
                    ll a = vpp[i].second-vpp[i].first+1;
                    ll b = vpp[j].second-vpp[j].first+1;
                    ll aux = min(a,b);
                    mx = max(aux,mx);
                }
            }            
        }
        cout<<mx<<"\n";
    }
    return 0;
}