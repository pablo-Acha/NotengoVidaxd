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
        set<ll> st;
        map<ll,ll> mp;
        vll arr(n);for(auto &a:arr){cin>>a;mp[a]++;}
        vll uni;
        vll fr;
        vll res(mp.size());
        for(auto [k,v]:mp){
            uni.push_back(k);
            fr.push_back(v);
        }
        if(uni[0] !=0){
            cout<<"-1\n";
            continue;
        }
        ll mx = 0;
        ll acc=0;
        bool f = 1;
        // for (int i = 0; i < fr.size(); i++)
        // {
        //     cout<<uni[i]<<" ";
        // }
        // cout<<"\n";
        // for (int i = 0; i < fr.size(); i++)
        // {
        //     cout<<fr[i]<<" ";
        // }
        // cout<<"\n";
        
        for (int i = 1; i < fr.size(); i++)
        {
            if((uni[i]-acc)%fr[i-1] == 0){
                if((uni[i]-acc)/fr[i-1]<=mx){
                    f = 0;

                    break;
                }
                res[i-1] = (uni[i]-acc)/fr[i-1];
                acc+= res[i-1]*fr[i-1];
                mx = res[i-1];
            }else{
                // cout<<"xx\n";
                f = 0;
                break;
            }
        }
        res[fr.size()-1] = mx+1;
        // for (int i = 0; i < fr.size(); i++)
        // {
        //     cout<<res[i]<<" ";
        // }
        // cout<<"\n";
        if(!f){
            cout<<"-1\n";
        }else{
            for (int i = 0; i < n; i++)
            {
                ll ind = lower_bound(all(uni),arr[i]) - uni.begin();
                cout<<res[ind]<<" ";
            }
            cout<<"\n";

        }
        
    }

    return 0;
}