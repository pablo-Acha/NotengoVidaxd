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
    while (t--)
    {
        ll n,k;cin>>n>>k;
        ll mx = (1LL<<n);
        ll res = 0;
        ll aux = k;
        ll cnt = 0;
        while(aux && mx){
            mx/=2;
            cnt++;
            if(mx <= aux){  
                aux-=mx;
            }
        }
        cout<<cnt<<"\n";
    }
    

    return 0;
}