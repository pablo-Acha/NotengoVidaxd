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
    while(t--)
    {
        ll n,m;cin>>n>>m;
        if(m>=n)cout<<-1<<"\n";
        else{
            ll res = 0;
            while(m>0&&n>m){
                res++;
                // cout<<m<<" "<<n<<"\n";
                n-=2;
                m--;
            }
            cout<<res<<"\n";
        }
    }

    return 0;
}