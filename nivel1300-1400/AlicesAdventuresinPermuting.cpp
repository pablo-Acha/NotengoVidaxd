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
        ll n,a,b;cin>>n>>a>>b;
        if(b >=n){
            cout<<n<<"\n";
            continue;
        }
        if(a == 0){
            if(n == b+1 || n == b+2){
                cout<<n-1<<"\n";
            }else{
                cout<<"-1\n";
            }
            continue;
        }
        ll res = (n-1-b)/a;
        cout<<(n-1-res)<<"\n";

    }

    return 0;
}