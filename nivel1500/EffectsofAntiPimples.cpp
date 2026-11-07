#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

const ll MOD = 998244353;

ll pot2[100100];
void init(){
    pot2[0] = 1;
    for (int i = 1; i <= 1e5; i++)
    {
        pot2[i] = (pot2[i-1]*2)%MOD; 
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();
    ll n;cin>>n;
    vll arr(n);for(auto &a:arr)cin>>a;
    priority_queue<ll> pq;
    for (int i = 1; i <= n; i++)
    {
        ll mx = 0;
        for (int j = i-1; j < n; j+=i)
        {
            mx= max(arr[j],mx);
        }
        pq.push(mx);
    }
    ll last = n-1;
    ll res = 0;
    while(n--){
        ll x = pq.top();
        pq.pop();
        ll p = pot2[last];
        res  = (res + (x * p)%MOD)%MOD;
        last--;
    }
    cout<<res<<"\n";
    return 0;
}