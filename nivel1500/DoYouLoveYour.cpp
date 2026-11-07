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
        vector<pll> res;
        ll mx = 500;ll x = 0;
        ll limit = 0;
        while(n*2>mx){
            ll add = 1;
            ll sum = 0;
            mx--;
            res.emplace_back(x,limit);
            limit++;
            while(n>=sum+add){
                sum+=add;
                add++;
                res.emplace_back(x,limit);
                limit++;
                mx--;
            }
            n-=sum;
            x++;
        }        
        // cout<<res.size()<<"\n";
        // cout<<n<<"\n";
        // cout<<mx<<"\n";
        for (int i = 0; i < n; i++)
        {
            res.emplace_back(x,limit);
            limit++;
            res.emplace_back(x,limit);
            limit++;
            x++;
        }
        
        cout<<res.size()<<"\n";
        for (int i = 0; i < res.size(); i++)
        {
            cout<<res[i].first<<" "<<res[i].second<<"\n";
        }
        
        
    }

    return 0;
}