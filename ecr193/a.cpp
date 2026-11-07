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
        ll mx = n+1;
        bool f = 1;
        for (int i = 2; i <= n; i++)
        {
            if(mx%i == 0){f = 0;break;}
        }
        cout<<(f?"YES":"NO")<<"\n";
        
    }

    return 0;
}