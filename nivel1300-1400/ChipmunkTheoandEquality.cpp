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
        if(n == 1){
            cout<<"0\n";
            continue;
        }
        sort(all(arr));
        map<ll,ll> mp;
        ll c = 0;
        while(true){
            if(mp.find(arr[0])!= mp.end())break;
            mp[arr[0]] = c;
            if(arr[0]&1)arr[0]++;
            else arr[0]/=2;
            c++;
        }
        // for(auto &[k,v]:mp){
        //     cout<<k<<" "<<v<<"\n";
        //     // res = min(v,res);
        // }
        for (int i = 1; i < n; i++)
        {
            map<ll,ll> aux;
            ll cnt = 0;
            while (true)
            {
                if(mp.find(arr[i]) !=mp.end()){
                    if(aux.find(arr[i])!= aux.end())break;
                    aux[arr[i]] = cnt +mp[arr[i]];
                }
                if(arr[i]&1)arr[i]++;
                else arr[i]/=2;
                cnt++;
            }
            mp.clear();
            for(auto &[k,v]:aux){
                mp[k] = v;
            }
        }
        ll res = 1e9;
        for(auto &[k,v]:mp){
            // cout<<k<<" "<<v<<"\n";
            res = min(v,res);
        }
        cout<<res<<"\n";
        
    }

    return 0;
}