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
        ll n,m;cin>>n>>m;
        n--;
        vector<pll> res;
        if(n%2 == 0 && n){res.push_back({n,n});n--;}
        if(n>0)for (int i = (n+1)/2,j = 1; i <= n; i++,j++)
        {
            res.push_back({j,i});
        }
        cout<<res.size()<<"\n";
        for(auto [x,y]:res){
            cout<<x<<" "<<y<<"\n";
        }
    }

    return 0;
}