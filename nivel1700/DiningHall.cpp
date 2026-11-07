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
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        multiset<tuple<ll,ll,ll>> brr;
        for (int i = 1; brr.size()<=n; i+=3)
        {
            ll x = 1,y = i;
            while(y>0 && brr.size()<=n){
                brr.insert({x+y,x,y});
                x+=3;
                y-=3;
            }
        }

        multiset<tuple<ll,ll,ll>> mt;
        for (int i = 1; mt.size()<=n*4; i+=3)
        {
            ll x = 1,y = i;
            while(y>0 && mt.size()<=n*4){
                mt.insert({x+y,x,y});
                mt.insert({x+y+1,x,y+1});
                mt.insert({x+1+y,x+1,y});
                mt.insert({x+y+4,x+1,y+1});
                x+=3;
                y-=3;
            }
        }
        // for(auto [w,x,y]:brr)cout<<w<<" "<<x<<" "<<y<<"\n";
        // cout<<"\n";
        // for (auto it = mt.begin(); ; )
        // {
        //     auto [w,x,y] = *it;
        //     cout<<w<<" "<<x<<" "<<y<<"\n";
        //     it++;
        //     if(it == mt.end())break;
        // }
        
        for (int i = 0; i < n; i++)
        {
            if(!arr[i]){
                auto [w,x,y] = *brr.begin();
                if(mt.find(*brr.begin()) !=mt.end())mt.erase({w,x,y});
                brr.erase(brr.begin());
                cout<<x<<" "<<y<<"\n";
            }else{
                auto [w,x,y] = *mt.begin();
                if(brr.find(*mt.begin()) !=brr.end())brr.erase({w,x,y});
                mt.erase(mt.begin());
                cout<<x<<" "<<y<<"\n";
            }
        }
        
        
    }

    return 0;
}