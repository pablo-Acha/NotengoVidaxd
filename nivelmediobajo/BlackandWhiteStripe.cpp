#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll m,n;cin>>n>>m;
        
        string s;cin>>s;
        ll w = 0;
        ll res = 1e9;
        for (int i = 0; i < m; i++)
        {
            if(s[i] == 'W')w++;
        }
        res = min(res,w);
        for (int i = 0; i+m < n; i++)
        {
            w = w-(s[i] =='W')+(s[i+m] == 'W'); 
            res= min(w,res);
        }
        cout<<res<<"\n";
    }
    return 0;
}