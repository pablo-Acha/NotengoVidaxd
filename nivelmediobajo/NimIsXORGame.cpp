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
        ll res = 1;
        for (ll i = 31; i >=0; i--)
        {
            ll cont = 0;
            for (ll j = 0; j < n; j++)
            {
                cont+= (arr[j]>>i)&1;
            }
            if(cont&1){
                res = cont;
                break;
            }
        }
        cout<<res<<"\n";
    }

    return 0;
}