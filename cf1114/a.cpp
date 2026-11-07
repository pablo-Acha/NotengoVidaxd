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
        vll arr(3);
        for (int i = 0; i < 3; i++)
        {
            cin>>arr[i];
        }
        sort(all(arr));
        ll res = min(arr[2]-arr[1],arr[1]-arr[0]);
        cout<<res<<"\n";
        
    }

    return 0;
}