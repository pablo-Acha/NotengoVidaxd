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
        ll n;cin>>n;
        ll c = 0,u = 0;
        for (int i = 0; i < n; i++)
        {
            ll a;cin>>a;
            c += a== 0;
            u += a== 1;
        }
        cout<<(c>u?"Elsie\n":"Bessie\n");
        
    }
    

    return 0;
}