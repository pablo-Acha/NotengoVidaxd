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
        ll act = n-1;
        for (int i = 0; i < n-1; i++)
        {
            cout<<i+1<<" "<<i+2<<"\n";
        }
        
        for (int i = 0; i < q; i++)
        {
            ll d;cin>>d;
            if(d == act){
                cout<<"-1 -1 -1\n";
            }else{
                cout<<n<<" "<<act<<" "<<d<<"\n";
                act = d;
            }
        }
        
    }

    return 0;
}