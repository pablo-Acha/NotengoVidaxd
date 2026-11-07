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
        ll n,m;cin>>n>>m;
        string s;cin>>s;
        string c;cin>>c;
        string x;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == 's'){
                s.erase(s.begin()+i);
                break;
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'i'){
                s.erase(s.begin()+i);
                break;
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'x'){
                s.erase(s.begin()+i);
                break;
            }
        }
        sort(all(c));
        sort(all(s));
        cout<<(c == s?"YES\n":"NO\n");
    }

    return 0;
}