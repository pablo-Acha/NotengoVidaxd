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
        string s;cin>>s;
        string c;cin>>c;
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt+= s[i] == 'f';
            cnt+= c[i] == 'f';
        }
        cout<<(cnt&1?1:0)<<"\n";
    }

    return 0;
}