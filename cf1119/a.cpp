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
        ll n,k;cin>>n>>k;
        string s;cin>>s;
        ll res = 0,cnt = 0;

        for (int i = 0,j = 0; i < n; i++,j++)
        {
            
            cnt += s[i] == '1';
            if(j== k-1){
                j = -1;
                // cout<<cnt<<"\n";
                res += cnt == k;
                cnt = 0;
            }
        }
        cout<<res<<"\n";
        
    }


    return 0;
}