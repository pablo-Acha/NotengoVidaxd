#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;

    while(t--){
        ll n,k;cin>>n>>k;
        vll arr(n);
        for(auto &a:arr)cin>>a;
        vll primos;
        ll x = k;
        for (ll i = 2; i*i <= x; i++)
        {
            if(x%i)continue;
            primos.push_back(i);
            while(x%i==0)
            {
                x/=i;
            }
        }
        if(x>1)primos.push_back(x);
        ll ans = 0;
        for(auto p:primos){
            ll cnt = 0;
            for(auto a:arr){
                if(a%p==0)
                {
                    cnt+=a;
                }
            }
            ans=max(ans,cnt);
        }
        cout<<ans<<"\n";
    }

    return 0;
}