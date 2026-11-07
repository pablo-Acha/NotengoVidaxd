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
        vll arr(n);for(auto &a:arr)cin>>a;
        vll fr(n+1);
        ll mx = 0;
        for (int i = 0; i < n; i++)
        {
            fr[arr[i]]++;
        }
        bool f= 0;
        // for(auto x:fr)cout<<x<<" ";cout<<"\n";
        for (int i = 0; i < n; i++)
        {
            if(fr[i]>=k*2){
                continue;
            }else if(fr[i] == (k*2)-1){
                f = 1;
                break;
            }else {
                
                break;
            }
        }
        cout<<(f? "YES\n":"NO\n");
        
    }

    return 0;
}