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
        ll n, k;cin>>n>>k;
        vll arr(n);for(auto &a:arr)cin>>a;
        string s;cin>>s;
        bool f = 1;
        
        ll mx  = 0;
        ll acc = 0;
        for (int i = 0; i < n; i++)
        {
            acc += arr[i];
            if(acc<=0)acc = 0;
            ll mx = max(acc,mx);            
        }
        if(acc == k){
            cout<<"YES\n";
            continue;
        }
                
        for (int i = 0; i < n; i++)
        {
            if(s[i] == 0){f = 0;break;}
        }
        if(f){
        }else{

        }
        
    }

    return 0;
}