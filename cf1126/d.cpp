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
        ll n,m,k;cin>>n>>m>>k;
        vector<pll> arr(n);
        for(auto &[x,y]:arr)cin>>x>>y;
        sort(all(arr));
        vector<pll> brr;
        pll aux = {0,0};
        for (int i = 0; i < n; i++)
        {
            auto [q,w] = arr[i];
            if(q>aux.second){
                if(aux.first != 0)brr.push_back(aux);
                aux = {q,w};
            }else{
                aux = {aux.first,w};
            }
        }
        brr.push_back(aux);
        bool f = 0;
        vll crr(brr.size());
        
        
        for (int i = brr.size() - 1; i >= 0; i--)
        {
            if(k>brr[i].second-brr[i].first+1){
                k-=brr[i].second-brr[i].first;
            }else if(k == brr[i].second-brr[i].first+1){
                cout<<brr[i].second-k+1<<"\n";
                f = 1;
            }
        }
        if(!f)cout<<-1<<"\n";
        // vector<pll> crr;
        // ll last = 1;
        // for (int i = 0; i < brr.size(); i++)
        // {
        //     if(last == brr[i].first)crr.push_back({last,brr[i].first-1});
        //     last = brr[i].second;
        // }
        // crr.push_back({last,1e18});

    }

    return 0;
}