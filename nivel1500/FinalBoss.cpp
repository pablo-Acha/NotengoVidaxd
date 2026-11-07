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
        ll n,h;cin>>h>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll brr(n);for(auto &a:brr)cin>>a;
        map<ll,vector<pll>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[1].push_back({arr[i],brr[i]});
        }
        ll last = 1;
        while(true){
            auto b = mp.begin();
            for (int i = 0; i < b->second.size(); i++)
            {
                h-= b->second[i].first;
                mp[b->second[i].second+b->first].push_back(b->second[i]);
            }
            last = b->first;
            mp.erase(mp.begin());
            if(h <=0)break;
        }
        cout<<last<<"\n";
    }

    return 0;
}