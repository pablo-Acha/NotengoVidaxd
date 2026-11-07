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
        ll res = 0;
        for (int i = 0; i < n; )
        {
            if(s[i] == '#'){
                ll cnt = 0;
                while(i<n &&s[i] == '#'){
                    i++;
                    cnt++;
                }
                res = max(res, cnt/2 +(cnt&1));                                
            }else{
                i++;
            }
        }
        cout<<res<<"\n";
    }
    

    return 0;
}