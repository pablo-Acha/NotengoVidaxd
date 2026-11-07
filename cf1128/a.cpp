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
        ll mn = 1e9, mx = -1;
        ll cnt = 0;
        for (ll i = 0; i < n; i++)
        {
            if(s[i] == '1'){
                mn =min(i,mn);
                mx =max(i,mx);
                cnt++;
            }



        }
        if(cnt == 1){
            cout<<"0\n";
        }else if(cnt == 2){
            cout<<"1\n";
        }else{
            cout<<mx-mn<<"\n";
        }
    }

    return 0;
}