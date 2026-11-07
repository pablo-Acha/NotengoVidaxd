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
    while(t--)
    {
        ll n,m,k;cin>>n>>m>>k;
        ll mx = max(n,m);
        ll mn = min(n,m);
        if(mx-k>mn || k>mx){
            cout<<"-1\n";
        }else{
            if(m>n){
                ll j = 1;
                while (m ||n)
                {
                    ll aux = k;
                    if(j&1){
                        for (int i = 0; i < min(m,k); i++)
                        {
                            cout<<"1";
                        }                        
                        m-= min(m,k);
                    }else{
                        for (int i = 0; i < min(n,k); i++)
                        {
                            cout<<"0";
                        }
                        n -= min(n,k);
                    }
                    j++;
                }
            }else{
                ll j = 1;
                while(n || m){
                    if(j&1){
                        for (int i = 0; i < min(n,k); i++)
                        {
                            cout<<"0";
                        }                        
                        n-= min(n,k);
                    }else{
                        for (int i = 0; i < min(m,k); i++)
                        {
                            cout<<"1";
                        }
                        m -= min(m,k);
                    }
                    j++;
                }
            }
            cout<<"\n";
        }
    }

    return 0;
}