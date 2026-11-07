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
        if(n == 2){
            cout<<"-1\n";
            continue;
        }else if(n == 1){
            cout<<"1\n";
            continue;
        }
        ll val = 1;
        for (int i = 0; i < n-2; i++)
        {
            cout<<val*3<<" ";
            val*=2;
        }
        cout<<1<<" "<<2<<"\n";
           
    }

    return 0;
}