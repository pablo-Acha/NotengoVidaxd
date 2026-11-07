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
        vll arr(n);for(auto &a:arr)cin>>a;
        vll brr(m);for(auto &a:brr){cin>>a;a--;}
        sort(all(brr));
        ll res = 0;
        for (int i = n - 1; i > brr[brr.size()-1]; i--)
        {
            res+= arr[i];
        }
        for (int i = m - 1; i >= 0; i--)
        {
            ll mn = 0;
            if(i>0)mn = brr[i-1]+1;
            ll acc = 0;
            for (int j = brr[i]; j >=mn; j--)
            {
                acc+= arr[j];
            }
            // cout<<acc<<"\n";
            res += max(acc,acc*-1);
        }
        cout<<res<<"\n";
        
    }

    return 0;
}