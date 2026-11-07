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
        vll arr(n);for(auto &a:arr)cin>>a;
        string s;cin>>s;

        ll A = 0,B = 0;
        vll pref(n+1);
        for (int i = 0; i < n; i++)
        {
            pref[i+1] = arr[i] ^pref[i];
            if(s[i] == '1'){
                A = A ^ arr[i];
            }else{
                B = B ^ arr[i];
            }
        }
        
        ll q;cin>>q;
        for (int i = 0; i < q; i++)
        {
            ll a;cin>>a;
            if(a == 1){
                ll l,r;cin>>l>>r;
                A = A ^ (pref[r]^pref[l-1]);
                B = B ^ (pref[r]^pref[l-1]);
            }else{
                ll x;cin>>x;
                cout<<(x==1?A:B)<<" ";
            }
        }
        cout<<"\n";
        
    }

    return 0;
}