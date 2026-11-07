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
        char c;cin>>c;
        string s;cin>>s;
        ll res = 0;
        for (int i = 0,j = n-1; i < j; i++,j--)
        {
            if(s[i]!=s[j])
            {
                res += s[i]!=c;
                res += s[j]!=c;
            }
        }
        cout<<res<<"\n";
    }

    return 0;
}