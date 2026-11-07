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
        ll n,q;cin>>n>>q;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll u(n+1),c(n+1);
        for (int i = 1; i <= n; i++)
        {
            u[i] = u[i-1]+(arr[i-1] == 1);
            c[i] = c[i-1]+(arr[i-1] == 0);
        }
        vll junt(n+1);
        for (int i = 2; i <= n; i++)
        {   
            junt[i] = junt[i-1]+(arr[i-1] ==arr[i-2]);
        }
        
        for (int i = 0; i < q; i++)
        {
            ll l,r;cin>>l>>r;
            if((r-l+1)%3 == 0 && (u[r]-u[l-1])%3 == 0 && (c[r]-c[l-1])%3 == 0){
                ll res = (u[r]-u[l-1])/3 + (c[r]-c[l-1])/3;
                if(junt[r]-junt[l]==0)res++;
                cout<<res<<"\n";
            }else{
                cout<<"-1"<<"\n";
            }
        }   
        
    }

    return 0;
}