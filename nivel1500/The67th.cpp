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
        ll e,o;cin>>e>>o;
        ll sum = e+o;
        if(sum&1)o--;
        else e--;

        if(e>o || e<0 || o<0){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
            ll aux = o-e;
            // if(e>0)cout<<1<<" "<<2<<"\n";
            ll j = 2;
            for (int i = 0; i < e; i++,j+=2)
            {
                cout<<j-1<<" "<<j<<"\n";
                cout<<j<<" "<<j+1<<"\n";
            }
            for (int i = 0; i < aux; i++,j++)
            {
                cout<<1<<" "<<j<<"\n";
            }
            
        }
        
    }

    return 0;
}