#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

ll comb(ll n,ll k){
    ll up = 1;
    for (int i = 1; i <= n; i++)
    {
        up*= i;
    }
    ll down = 2;
    for (int i = 1; i <= n-2; i++)
    {
        down*=i;
    }
    return up/down;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vll pre(10);
    for (int i = 0; i < 10; i++)
    {
        pre[i] = comb(i+2,2);
    }
    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        ll res = 1;
        do{
            res*= pre[n%10];
            n/=10;
        }while (n);
        cout<<res<<"\n";
        
    }

    

    return 0;
}