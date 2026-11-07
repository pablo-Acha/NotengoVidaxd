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
        for (int i = 0; i < n; i++)
        {
            vll pre(n),suf(n);
            ll j = (i+n+1)%n ;
            while (j!=i)
            {
                pre[(j+n)%n]=max(pre[(j-1+n)%n],arr[(j-1+n)%n]);
                j = (j+n+1)%n;
                // cout<<j<<"\n";
            }
            j = (i-1+n)%n;
            while (j!=i)
            {
                suf[(j+n)%n]=max(suf[(j+1+n)%n],arr[(j+n)%n]);
                j = (j+n-1)%n;
            }
            ll res = 0;
            for (int i = 0; i < n; i++)
            {
                res += min(pre[i],suf[i]);
            }
            cout<<res<<" ";
            // if(i == 1){
            //     for(auto a:pre)cout<<a<<" ";
            //     cout<<"\n";
            //     for(auto a:suf)cout<<a<<" ";
            //     cout<<"\n";
            // }
        }
        cout<<"\n";
    }

    return 0;
}