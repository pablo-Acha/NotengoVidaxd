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
        bool f= 0;
        for (int i = 1; i < n-1; i++)
        {
            if(arr[i]!=1){
                f = 1;
                break;
            }
        }
        if(f){
            ll acc = accumulate(all(arr),0LL);
            cout<<acc-1<<"\n";
        }else{
            if(arr[0] == arr[n-1] && arr[0] == 1){
                cout<<"-1\n";
            }else{
                ll res = arr[0]+arr[n-1]-1;
                cout<<res<<"\n";
            }
        }
        
    }

    return 0;
}