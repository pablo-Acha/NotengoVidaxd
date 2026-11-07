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
        ll res = 0;
        vll arr(n);for(auto &a:arr)cin>>a;
        for (int i = n - 2; i >= 0; i--)
        {
            if(arr[i]>arr[i+1]){
                ll mod = arr[i]%arr[i+1];
                ll div = arr[i]/arr[i+1];
                if(mod== 0){
                    arr[i] = arr[i+1];
                    res+= div-1;
                }else{
                    ll sum = (arr[i+1]-mod)*div;
                    ll act = mod+(sum/(div+1));
                    arr[i] = act;
                    res+= div;
                }
            }
        }
        cout<<res<<"\n";
        
    }

    return 0;
}