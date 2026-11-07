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
        ll n,x,y;cin>>n>>x>>y;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll ord = arr;
        sort(all(ord));
        bool f = 1;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]!=ord[i]){
                ll aux = abs(ord[i]-arr[i]);
                if(aux%gcd(x,y) !=0){
                    f = 0;
                    break;
                }
            }
        }
        cout<<(f?"YES\n":"NO\n");        
    }

    return 0;
}