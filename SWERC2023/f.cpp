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

    ll n;cin>>n;
    vector<tuple<ll,ll,string>> res;
    for (int i = 0; i < n; i++)
    {
        string s;cin>>s;
        ll x;cin>>x;
        deque<ll> arr(6);
        ll sum = 0;
        for(auto &x:arr){cin>>x;sum+= x;}
        sort(all(arr));
        sum-=(arr[0]+arr[5]);
        sum+= x*10;
        res.push_back({sum,n-i,s});
    }
    sort(all(res));
    // ll cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        auto [val,ind,s] = res[i];
        tuple<ll,ll,string> x = {val,1e10,s};
        ll p = upper_bound(all(res),x)-res.begin();
        
        ll cnt = n-p;
        if(cnt>2)break;
        cout<<s<<" "<<val<<"\n";
    }
    
    
    

    return 0;
}