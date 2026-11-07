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
        ll l  =0,r  = (2*n) -1;

        while(l<=r){
            // cout<<s[l]<<" "<<s[r]<<"\n";
            if(s[l] == 'R' && s[r] == 'B'){
                res++;
                l++;
                r--;
            }else{
                if(s[l] =='B')l++;
                if(s[r] == 'R')r--;
            }
        }
        cout<<res<<"\n";
    }

    return 0;
}