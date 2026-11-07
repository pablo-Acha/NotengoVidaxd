#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

ll f(ll n){
    ll cnt = 0;
    for (int i = 1; i*i <= n; i++)
    {
        if(n%i == 0){
            cnt++;
            if(i*i!=n)cnt++;
        }
    }
    return cnt;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll mx= 0;
    for (int i = 2; i <= 2e5; i++)
    {
        ll x = f(i);
        mx = max(x,mx);
    }
    cout<<mx<<"\n";

    return 0;
}