
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
        ll n, m;
        cin>>n>>m;
    
        if (2*m < n-1) {
            cout<<-1<<'\n';
            continue;
        }
    
        ll k = n / 2;
        cout << k*(k+1)/2 << '\n';

    }

    return 0;
}
